/*
https://dmoj.ca/problem/cco10p2
*/
#include <bits/stdc++.h>

using namespace std;

int node[300], dp[300][601];
const int CON = 300, MAX = 2e9;
vector<int> arr[300];

void recurse(int cur)
{
    dp[cur][CON] = 1;
    dp[cur][CON+node[cur]] = arr[cur].size();
    for (int i : arr[cur])
    {
        recurse(i);
    }
    if (arr[cur].size() == 1)
    {
        for (int i = 0; i <= 600; i++)
        {
            if (dp[arr[cur][0]][i] != MAX)
            {
                dp[cur][i+node[cur]] = min(dp[cur][i+node[cur]], dp[arr[cur][0]][i]);
            }
        }
    }
    else if (arr[cur].size() == 2)
    {
        for (int i = 0; i <= 600; i++)
        {
            if (dp[arr[cur][0]][i] != MAX)
            {
                dp[cur][i+node[cur]] = min(dp[cur][i+node[cur]], dp[arr[cur][0]][i]+1);
                for (int j = 0; j <= 600; j++)
                {
                    dp[cur][i+j-CON+node[cur]] = min(dp[cur][i+j-CON+node[cur]], dp[arr[cur][0]][i]+dp[arr[cur][1]][j]);
                }
            }
        }
        for (int i = 0; i <= 600; i++)
        {
            dp[cur][i+node[cur]] = min(dp[cur][i+node[cur]], dp[arr[cur][1]][i]+1);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, d, a, b, c;
    cin>>n>>d;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b>>c;
        node[a] = (b?1:-1);
        for (int j = 0; j < c; j++)
        {
            cin>>b;
            arr[a].push_back(b);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= 600; j++)
        {
            dp[i][j] = MAX;
        }
    }
    recurse(0);
    cout<<(dp[0][d+CON]==MAX?-1:dp[0][d+CON]);
}
