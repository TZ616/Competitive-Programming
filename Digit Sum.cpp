/*
https://dmoj.ca/problem/dps
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int dp[10000][2][101], mod;
string s;

int recurse(int length, bool same, int sum)
{
    if (length == s.length())
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }
    if (dp[length][same][sum] != -1)
    {
        return dp[length][same][sum];
    }
    dp[length][same][sum] = 0;
    int temp = (same?s[length]-'0':9);
    for (int i = 0; i <= temp; i++)
    {
        dp[length][same][sum]+=recurse(length+1, same&&(i==temp), (sum+i)%mod);
        dp[length][same][sum]%=MOD;
    }
    return dp[length][same][sum];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>s>>mod;
    cout<<(recurse(0, 1, 0)-1+MOD)%MOD<<"\n";
}
