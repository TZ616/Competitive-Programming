/*
https://dmoj.ca/problem/dpp
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
vector<int> arr[100001];
long long dp[100001][2];

void recurse(int cur, int prev)
{
    dp[cur][0] = 1;
    dp[cur][1] = 1;
    for (int i : arr[cur])
    {
        if (i != prev)
        {
            recurse(i, cur);
            dp[cur][0]*=(dp[i][0]+dp[i][1]);
            dp[cur][1]*=dp[i][0];
            dp[cur][0]%=MOD;
            dp[cur][1]%=MOD;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, a, b;
    cin>>n;
    for (int i = 1; i < n; i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    recurse(1, 0);
    cout<<(dp[1][0]+dp[1][1])%MOD<<"\n";
}
