/*
https://dmoj.ca/problem/coci07c3p5
*/
#include <bits/stdc++.h>

using namespace std;

long long dp[3][15][136][2];
string s[3];

long long recurse(int cur, int size, int sum, bool same)
{
    if (size == s[cur].length())
    {
        return (sum==0);
    }
    if (dp[cur][size][sum][same] != -1)
    {
        return dp[cur][size][sum][same];
    }
    dp[cur][size][sum][same] = 0;
    int temp = (same?s[cur][size]-'0':9);
    for (int i = 0; i <= temp; i++)
    {
        dp[cur][size][sum][same]+=recurse(cur, size+1, sum-i, same&&(i==temp));
    }
    return dp[cur][size][sum][same];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    long long bot, top, mid;
    int sum;
    cin>>bot>>top>>sum;
    s[0] = to_string(bot-1);
    s[1] = to_string(top);
    cout<<recurse(1, 0, sum, 1)-recurse(0, 0, sum, 1)<<"\n";
    while (bot < top)
    {
        memset(dp[2], -1, sizeof(dp[2]));
        mid = (top+bot)/2;
        s[2] = to_string(mid);
        if (recurse(2, 0, sum, 1)-dp[0][0][sum][1] >= 1)
        {
            top = mid;
        }
        else
        {
            bot = mid+1;
        }
    }
    cout<<bot<<"\n";
}
