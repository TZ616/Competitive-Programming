/*
https://dmoj.ca/problem/bts16p5
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
vector<pair<int, int>> arr[10001];
pair<int, int> dp[10001];
int nodes[10001];

void recurse(int cur, int prev)
{
    dp[cur].first = nodes[cur];
    for (pair<int, int> i : arr[cur])
    {
        if (i.first != prev)
        {
            dp[i.first].second+=i.second;
            recurse(i.first, cur);
            dp[cur].first+=dp[i.first].first;
            dp[cur].second+=dp[i.first].second;
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, c, sum, weight, ans = 0;
    cin>>n>>sum>>weight;
    for (int i = 1; i <= n; i++)
    {
        cin>>nodes[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
        arr[b].push_back({a, c});
    }
    recurse(1, 0);
    for (int i = 2; i <= n; i++)
    {
        if (dp[i].first >= sum && dp[i].second <= weight)
        {
            ans++;
        }
    }
    cout<<ans<<"\n";
}
