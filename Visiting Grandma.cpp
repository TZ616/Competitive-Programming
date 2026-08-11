/*
https://dmoj.ca/problem/saco08p3
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e9, MOD = 1000000;
pair<int, int> dis[2][701];
int arr[701][701];
priority_queue<pair<int, pair<int, bool>>> pq;
bool vis[701];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, x, y, in;
    bool z;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>arr[i][j];
        }
        dis[0][i].first = MAX;
        dis[1][i].first = MAX;
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>in;
        vis[in] = true;
    }
    if (!vis[1])
    {
        dis[0][1].first = 0;
        dis[0][1].second = 1;
        pq.push({0, {1, 0}});
    }
    else
    {
        dis[1][1].first = 0;
        dis[1][1].second = 1;
        pq.push({0, {1, 1}});
    }
    while (!pq.empty())
    {
        x = -pq.top().first;
        y = pq.top().second.first;
        z = pq.top().second.second;
        pq.pop();
        if (x > dis[z][y].first)
        {
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == y)
            {
                continue;
            }
            if (x+arr[y][i] < dis[z|vis[i]][i].first)
            {
                dis[z|vis[i]][i].first = x+arr[y][i];
                dis[z|vis[i]][i].second = dis[z][y].second;
                pq.push({-(x+arr[y][i]), {i, z|vis[i]}});
            }
            else if (x+arr[y][i] == dis[z|vis[i]][i].first)
            {
                dis[z|vis[i]][i].second += dis[z][y].second;
                dis[z|vis[i]][i].second%=MOD;
            }
        }
    }
    cout<<dis[1][n].first<<" "<<dis[1][n].second<<"\n";
}
