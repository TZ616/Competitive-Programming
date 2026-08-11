/*
https://dmoj.ca/problem/lkp18c1p4
*/
#include <bits/stdc++.h>

using namespace std;

long long dis[100001], MAX;
vector<pair<int, pair<int, int>>> arr[100001];
priority_queue<pair<long long, int>> pq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c, bot = 0, mid, top, start, end, x;
    long long y;
    cin>>n>>m;
    top = m;
    for (int i = 1; i <= m; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back({i, {b, c}});
        arr[b].push_back({i, {a, c}});
    }
    cin>>start>>end>>MAX;
    while (bot <= top)
    {
        mid = (top+bot)/2;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = 1e12;
        }
        dis[start] = 0;
        pq.push({0, start});
        while (!pq.empty())
        {
            y = -pq.top().first;
            x = pq.top().second;
            pq.pop();
            if (dis[x] < y)
            {
                continue;
            }
            for (pair<int, pair<int, int>> i : arr[x])
            {
                if (mid < i.first)
                {
                    break;
                }
                if (dis[i.second.first] > y+i.second.second)
                {
                    dis[i.second.first] = y+i.second.second;
                    pq.push({-dis[i.second.first], i.second.first});
                }
            }
        }
        if (dis[end] > MAX)
        {
            bot = mid+1;
        }
        else
        {
            top = mid-1;
        }
    }
    cout<<(bot>m?-1:bot)<<"\n";
}
