/*
https://dmoj.ca/problem/coci06c5p6
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int SIZE = 200000, pv[2] = {131, 137}, mv[2] = {1000000007, 1000000009};
int p[2][SIZE], h[2][SIZE], inv[2][SIZE], length;
gp_hash_table<long long, bool> poss;
string s;

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
    //cout<<ans<<"\n";
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
    for (int i = 0; i < length; i++)
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

bool check(int len)
{
    long long temp, x, y;
    poss.clear();
    for (int i = 0; i <= length-len; i++)
    {
        x = hash_fast(0, i, i+len-1);
        y = hash_fast(1, i, i+len-1);
        temp = x*mv[1]+y;
        if (poss.find(temp) != poss.end())
        {
            return true;
        }
        poss.insert({temp, 0});
    }
    return false;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int bot = 1, top, mid;
    cin>>top>>s;
    length = top;
    P();
    rollhash();
    while (bot <= top)
    {
        mid = (bot+top)/2;
        if (check(mid))
        {
            bot = mid+1;
        }
        else
        {
            top = mid-1;
        }
    }
    cout<<bot-1<<"\n";
}
