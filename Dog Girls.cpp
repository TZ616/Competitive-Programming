/*
https://dmoj.ca/problem/halloween14p3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

const int SIZE = 5000, pv[2] = {131, 137}, mv[2] = {1000000007, 1000000009};
int p[2][SIZE], h[2][SIZE], inv[2][SIZE], length;
bool vis[SIZE][SIZE];
string s;
unordered_set<long long> poss;

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

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    length = s.length();
    int temp;
    long long h;
    P();
    rollhash();
    for (int i = 0; i < length; i++)
    {
        vis[i][i] = 1;
        for (int j = i; j < length; j++)
        {
            temp = j-i+1;
            if (vis[i][j+temp])
            {
                continue;
            }
            if (j+temp >= length)
            {
                break;
            }
            vis[i][j+temp] = true;
            if (hash_fast(0, i, j) == hash_fast(0, j+1, j+temp) && hash_fast(1, i, j) == hash_fast(1, j+1, j+temp))
            {
                h = hash_fast(0, i, j+temp);
                poss.insert(h*hash_fast(1, i, j+temp));
                for (int k = j+temp+1; k < length; k+=temp)
                {
                    if (k+temp > length)
                    {
                        break;
                    }
                    vis[i][k+temp-1] = true;
                    if (hash_fast(0, i, j) == hash_fast(0, k, k+temp-1) && hash_fast(1, i, j) == hash_fast(1, k, k+temp-1))
                    {
                        h = hash_fast(0, i, k+temp-1);
                        poss.insert(h*hash_fast(1, i, k+temp-1));
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    cout<<poss.size()<<"\n";
}
