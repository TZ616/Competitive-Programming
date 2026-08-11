/*
https://dmoj.ca/problem/cco15p2
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> arr[18];
int n, m, ans = 0, dp[18][1<<18];

void recurse(int cur, int length, int vis)
{
    if (cur == n-1)
    {
        ans = max(ans, length);
        return;
    }
    if (dp[cur][vis] >= length)
    {
        return;
    }
    dp[cur][vis] = length;
    for (pair<int, int> i : arr[cur])
    {
        if (((1<<i.first)&vis) == 0)
        {
            recurse(i.first, length+i.second, (vis|(1<<i.first)));
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
    }
    dp[0][1] = -1;
    recurse(0, 0, 1);
    cout<<ans<<"\n";
}
