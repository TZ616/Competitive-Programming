/*
https://dmoj.ca/problem/adigitproblem
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int dp[1000][2][1<<10], req = 0;
string s;

int recurse(int length, bool same, int vis)
{
    if (length == s.length())
    {
        if (vis == 0)
        {
            vis = 1;
        }
        if ((vis|req) == vis)
        {
            return 1;
        }
        return 0;
    }
    if (dp[length][same][vis] != -1)
    {
        return dp[length][same][vis];
    }
    dp[length][same][vis] = 0;
    int temp = (same?s[length]-'0':9);
    for (int i = 0; i <= temp; i++)
    {
        if (i == 0 && vis == 0)
        {
            dp[length][same][vis]+=recurse(length+1, same&&(i==temp), vis);
        }
        else
        {
            dp[length][same][vis]+=recurse(length+1, same&&(i==temp), vis|(1<<i));
        }
        dp[length][same][vis]%=MOD;
    }
    return dp[length][same][vis];
}

int main() 
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int n, in;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>in;
        req|=(1<<in);
    }
    cin>>s;
    cout<<recurse(0, 1, 0)<<"\n";;
}
