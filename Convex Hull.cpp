/*
https://dmoj.ca/problem/ccc15s4
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e9;
vector<pair<int, pair<int, int>>> arr[2001];
int dis[2001];
priority_queue<pair<pair<int, int>, int>> pq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int k, n, m, a, b, c, d, s, e, x, y, z;
    cin>>k>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        dis[i] = MAX;
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c>>d;
        arr[a].push_back({b, {c, d}});
        arr[b].push_back({a, {c, d}});
    }
    cin>>s>>e;
    pq.push({{k, 0}, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        x = pq.top().first.first;
        y = -pq.top().first.second;
        z = pq.top().second;
        pq.pop();
        dis[z] = min(y, dis[z]);
        if (dis[z] < y)
        {
            continue;
        }
        for (pair<int, pair<int, int>> i : arr[z])
        {
            if (dis[i.first] > y+i.second.first && x > i.second.second)
            {
                pq.push({{x-i.second.second, -(y+i.second.first)}, i.first});
            }
        }
    }
    cout<<(dis[e]==MAX?-1:dis[e])<<"\n";
}
