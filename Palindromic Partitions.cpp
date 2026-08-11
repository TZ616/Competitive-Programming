/*
https://dmoj.ca/problem/ceoi17p5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int SIZE = 1000000, pv[2] = {131, 137}, mv[2] = {1000000007, 1000000009};
int p[2][SIZE], h[2][SIZE], inv[2][SIZE];
string s;
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
    int t, pos1, pos2, ans, temp;
    P();
    cin>>t;
    while (t--)
    {
        ans = 0;
        cin>>s;
        pos1 = 0;
        pos2 = s.length()-1;
        rollhash();
        temp = s.length()/2;
        for (int i = 0; i < temp; i++)
        {
            if (hash_fast(0, pos1, i) == hash_fast(0, s.length()-i-1, pos2) && hash_fast(1, pos1, i) == hash_fast(1, s.length()-i-1, pos2))
            {
                ans+=2;
                pos1 = i+1;
                pos2 = s.length()-i-2;
            }
        }
        if (pos1 <= pos2)
        {
            ans++;
        }
        cout<<ans<<"\n";
    }
}
