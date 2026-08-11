/*
https://dmoj.ca/problem/ecoo16r2p1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int SIZE = 1000000, pv[2] = {131, 137}, mv[2] = {1000000007, 1000000009};
int p[2][SIZE], h[2][2][SIZE], inv[2][SIZE], length, temp = -1;
string s, s1;

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
    h[0][0][0] = 0;
    h[0][1][0] = 0;
    h[1][0][0] = 0;
    h[1][1][0] = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (i != 0)
            {
                h[0][j][i] = h[0][j][i-1];
                h[1][j][i] = h[1][j][i-1];
            }
            h[0][j][i] = (h[0][j][i]+((long long)(s[i])*p[j][i])%mv[j])%mv[j];
            h[1][j][i] = (h[1][j][i]+((long long)(s1[i])*p[j][i])%mv[j])%mv[j];
        }
    }
}

int hash_fast(int num, int index, int l, int r)
{
    if (l == 0)
    {
        return h[num][index][r];
    }
    int ans = ((h[num][index][r]-h[num][index][l-1])%mv[index]+mv[index])%mv[index];
    ans = ((long long)ans*inv[index][l])%mv[index];
    return ans;
}

int sol()
{
    int size = 1;
    for (int i = s.length()-1; i > 0; i--)
    {
        //cout<<s.substr(0, i+1)<<" "<<s1.substr(s.length()-i-1, i+1)<<"\n";
        //cout<<hash_fast(0, 0, 0, i)<<" "<<hash_fast(1, 0, s.length()-i-1, s.length()-1)<<" "<<hash_fast(0, 1, 0, i)<<" "<<hash_fast(1, 1, s.length()-i-1, s.length()-1)<<"\n";
        if (hash_fast(0, 0, 0, i) == hash_fast(1, 0, s.length()-i-1, s.length()-1) && hash_fast(0, 1, 0, i) == hash_fast(1, 1, s.length()-i-1, s.length()-1))
        {
            size = max(size, i+1);
            break;
        }
    }
    for (int i = 0; i < s.length()-1; i++)
    {
        //cout<<s.substr(i, s.length()-i)<<" "<<s1.substr(0, s.length()-i)<<"\n";
        if (hash_fast(0, 0, i, s.length()-1) == hash_fast(1, 0, 0, s.length()-i-1) && hash_fast(0, 1, i, s.length()-1) == hash_fast(1, 1, 0, s.length()-i-1))
        {
            size = max(size, (int)s.length()-i);
            break;
        }
    }
    //cout<<size<<"\n";
    return size;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    P();
    for (int i = 0; i < 10; i++)
    {
        cin>>s;
        s1 = s;
        reverse(s1.begin(), s1.end());
        rollhash();
        cout<<s.length()-sol()<<"\n";
    }
}
