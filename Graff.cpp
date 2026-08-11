/*
https://dmoj.ca/problem/grafftrip
*/
#include <bits/stdc++.h>

using namespace std;

const long long MAX = 1e18;
long long dis[101][10001], dis1[101];
vector<pair<int, int>> arr[10001];
bool vis[10001];
priority_queue<pair<long long, int>> pq;
priority_queue<pair<pair<long long, long long>, int>> pq1;
int nums[101], e;
unordered_map<int, int> h;

void dijk(int it, int s)
{
    long long x;
    int y;
    dis[it][s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        x = -pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (dis[it][y] < x)
        {
            continue;
        }
        for (pair<int, int> j : arr[y])
        {
            if (dis[it][j.first] > x+j.second)
            { 
                dis[it][j.first] = x+j.second;
                if (!vis[j.first] && j.first != e)
                {
                    pq.push({-(x+j.second), j.first});
                }
            }
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, a, b, c, s, t, z;
    long long M, ans = MAX, x, y;
    cin>>n>>m>>s>>e>>M;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        arr[a].push_back({b, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[0][i] = MAX;    
    }
    dijk(0, s);
    h[s] = 0;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin>>nums[i];
        h[nums[i]] = i;
        vis[nums[i]] = true;
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = MAX;
        }
        dijk(i, nums[i]);
        dis1[i] = MAX;
    }
    pq1.push({{0, 0}, s});
    while (!pq1.empty())
    {
        x = -pq1.top().first.first;
        y = -pq1.top().first.second;
        z = h[pq1.top().second];
        pq1.pop();
        dis1[z] = min(dis1[z], y);
        if (dis1[z] < y)
        {
            continue;
        }
        for (int i = 1; i <= t; i++)
        {
            if (x+dis[z][nums[i]] <= M && max(y, dis[z][nums[i]]) < dis1[h[nums[i]]])
            {
                pq1.push({{-(x+dis[z][nums[i]]), -max(y, dis[z][nums[i]])}, nums[i]});
            }
        }
        if (dis[z][e]+x <= M)
        {
            ans = min(ans, max(y, dis[z][e]));
        }
    }
    cout<<(ans==MAX?-1:ans)<<"\n";
}
