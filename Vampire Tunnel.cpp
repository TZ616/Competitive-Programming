/*
https://dmoj.ca/problem/cco11p2
*/
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, bool>>> arr[1600];
int dis[1600][3601], MN = 2e9;;
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int s, n, e, a, b, c, x, y, z, cur_min = MN;
    bool d;
    cin>>s>>n>>e;
    for (int i = 0; i < e; i++)
    {
        cin>>a>>b>>c>>d;
        arr[a].push_back({b, {c, d}});
        arr[b].push_back({a, {c, d}});
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dis[i][j] = MN;
        }
    }
    for (int i = 0; i <= s; i++)
    {
        dis[0][i] = 0;
    }
    pq.push({{0, 0}, 0});
    while (!pq.empty())
    {
        x = pq.top().first.first;
        y = pq.top().first.second;
        z = pq.top().second;
        pq.pop();
        if (dis[z][y] > x)
        {
            continue;
        }
        for (pair<int, pair<int, bool>> i : arr[z])
        {
            if (i.second.second)
            {
                if (y+i.second.first <= s && x+i.second.first < dis[i.first][y+i.second.first])
                {
                    dis[i.first][y+i.second.first] = x+i.second.first;
                    pq.push({{x+i.second.first, y+i.second.first}, i.first});
                }
            }
            else
            {
                if (x+i.second.first < dis[i.first][y])
                {
                    dis[i.first][y] = x+i.second.first;
                    pq.push({{x+i.second.first, y}, i.first});
                }
            }
        }
    }
    for (int i = 0; i <= s; i++)
    {
        cur_min = min(cur_min, dis[n-1][i]);
    }
    if (cur_min == MN)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<cur_min<<"\n";
    }
}
