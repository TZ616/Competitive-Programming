/*
https://dmoj.ca/problem/gfssoc2s4
*/
#include <bits/stdc++.h>

using namespace std;

const int MN = 500001, MAXN = 2e9;
int dis1[MN], dis2[MN];
vector<pair<int, int>> arr1[MN], arr2[MN];
vector<pair<pair<int, int>, int>> v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, d, a, b, c, y;
    long long x, mini, temp;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        arr1[a].push_back({b, c});
        arr2[b].push_back({a, c});
    }
    cin>>d;
    for (int i = 0; i < d; i++)
    {
        cin>>a>>b>>c;
        v.push_back({{a, b}, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis1[i] = MAXN;
        dis2[i] = MAXN;
    }
    pq.push({0, 1});
    while (!pq.empty())
    {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (dis1[y] < x)
        {
            continue;
        }
        dis1[y] = x;
        for (pair<int, int> i : arr1[y])
        {
            if (x+i.second < dis1[i.first])
            {
                dis1[i.first] = x+i.second;
                pq.push({x+i.second, i.first});
            }
        }
    }
    pq.push({0, n});
    while (!pq.empty())
    {
        x = pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (dis2[y] < x)
        {
            continue;
        }
        dis2[y] = x;
        for (pair<int, int> i : arr2[y])
        {
            if (x+i.second < dis2[i.first])
            {
                dis2[i.first] = x+i.second;
                pq.push({x+i.second, i.first});
            }
        }
    }
    mini = dis1[n];
    for (int i = 0; i < d; i++)
    {
        temp = dis1[v[i].first.first];
        temp+=v[i].second;
        temp+=dis2[v[i].first.second];
        mini = min(mini, temp);
    }
    if (mini == MAXN)
    {
        cout<<-1<<"\n";
    }
    else
    {
        cout<<mini<<"\n";
    }
}
