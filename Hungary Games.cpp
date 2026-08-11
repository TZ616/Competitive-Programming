/*
https://dmoj.ca/problem/cco12p2
*/
#include <bits/stdc++.h>

using namespace std;

const int MN = 20001, MAX = 2e9;
int dis1[MN], dis2[MN];
vector<pair<int, int>> arr[MN];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c, x, y;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis1[i] = MAX;
        dis2[i] = MAX;
    }
    pq.push({0, 1});
    while (!pq.empty())
    {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (x == dis1[y] || x >= dis2[y])
        {
            continue;
        }
        if (x < dis1[y])
        {
            dis2[y] = dis1[y];
            dis1[y] = x;
        }
        else
        {
            dis2[y] = x;
        }
        for (pair<int, int> i : arr[y])
        {
            if (x+i.second != dis1[i.first] && x+i.second < dis2[i.first])
            {
                pq.push({x+i.second, i.first});
            }
        }
    }
    if (dis2[n] == MAX)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<dis2[n]<<"\n";
    }
}
