/*
https://dmoj.ca/problem/ccc20s3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int SIZE = 200000, pv[2] = {131, 137}, mv[2] = {1000000007, 1000000009};
int p[2][SIZE], h[2][SIZE], inv[2][SIZE], length, temp = -1, freq[2][26];
string s, s1;
gp_hash_table<long long, bool> poss;

long long fast(long long a, long long n, int index)
{
    long long ans = 1;
    while (n > 0)
    {
        if (n&1)
        {
            ans*=a;
            ans%=mv[index];
        }
        a*=a;
        a%=mv[index];
        n>>=1;
    }
    return ans;
}

void P()
{
    p[0][0] = 1;
    p[1][0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            p[j][i] = ((long long)p[j][i-1]*pv[j])%mv[j];
            inv[j][i] = fast(p[j][i], mv[j]-2, j);
        }
    }
}

void rollhash()
{
    h[0][0] = 0;
    h[1][0] = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i != 0)
            {
                h[j][i] = h[j][i-1];
            }
            h[j][i] = (h[j][i]+((long long)(s[i])*p[j][i])%mv[j])%mv[j];
        }
    }
}

int hash_fast(int index, int l, int r)
{
    if (l == 0)
    {
        return h[index][r];
    }
    int ans = ((h[index][r]-h[index][l-1])%mv[index]+mv[index])%mv[index];
    ans = ((long long)ans*inv[index][l])%mv[index];
    return ans;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long temp;
    bool same;
    cin>>s1>>s;
    P();
    rollhash();
    for (int i = 0; i < s1.length(); i++)
    {
        freq[0][s1[i]-'a']++;
        freq[1][s[i]-'a']++;
    }
    for (int i = s1.length(); i < s.length(); i++)
    {
        same = true;
        for (int j = 0; j < 26 && same; j++)
        {
            if (freq[0][j] != freq[1][j])
            {
                same = false;
            }
        }
        if (same)
        {
            temp = hash_fast(0, i-s1.length(), i-1);
            temp*=hash_fast(1, i-s1.length(), i-1);
            if (poss.find(temp) == poss.end())
            {
                poss.insert({temp, 0});
            }
        }
        freq[1][s[i-s1.length()]-'a']--;
        freq[1][s[i]-'a']++;
    }
    same = true;
    for (int j = 0; j < 26 && same; j++)
    {
        if (freq[0][j] != freq[1][j])
        {
            same = false;
        }
    }
    if (same)
    {
        temp = hash_fast(0, s.length()-s1.length(), s.length()-1);
        temp*=hash_fast(1, s.length()-s1.length(), s.length()-1);
        if (poss.find(temp) == poss.end())
        {
            poss.insert({temp, 0});
        }
    }
    cout<<poss.size()<<"\n";
}
