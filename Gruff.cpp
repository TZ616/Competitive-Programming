/*
https://dmoj.ca/problem/cco14p2
*/
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e9+1;
map<int, int> psa;
vector<pair<int, pair<int, int>>> arr[100001], arr1[100001];
priority_queue<pair<int, int>> pq;
int dis1[100001], dis2[100001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, s, e, a, b, c, d, x, y, temp, q;
    cin>>n>>m>>s>>e;
    map<int, int>::iterator it1, it2;
    for (int i = 1; i <= n; i++)
    {
        dis1[i] = MAX;
        dis2[i] = MAX;
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c>>d;
        arr[a].push_back({b, {c, d}});
        arr1[b].push_back({a, {c, d}});
    }
    pq.push({0, s});
    dis1[s] = 0;
    dis2[e] = 0;
    while (!pq.empty())
    {
        x = -pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (x > dis1[y])
        {
            continue;
        }
        for (pair<int, pair<int, int>> i : arr[y])
        {
            if (dis1[i.first] > x+i.second.first)
            {
                dis1[i.first] = x+i.second.first;
                pq.push({-dis1[i.first], i.first});
            }
        }
    }
    pq.push({0, e});
    while (!pq.empty())
    {
        x = -pq.top().first;
        y = pq.top().second;
        pq.pop();
        if (x > dis2[y])
        {
            continue;
        }
        for (pair<int, pair<int, int>> i : arr1[y])
        {
            if (dis2[i.first] > x+i.second.first)
            {
                dis2[i.first] = x+i.second.first;
                pq.push({-dis2[i.first], i.first});
            }
        }
    }
    psa[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (pair<int, pair<int, int>> j : arr[i])
        {
            temp = dis1[i]+dis2[j.first]+j.second.first;
            if (temp < MAX)
            {
                psa[temp]+=j.second.second;
            }
        }
    }
    it1 = psa.begin();
    it2 = psa.begin();
    it1++;
    while (it1 != psa.end())
    {
        psa[(*it1).first]+=(*it2).second;
        it1++;
        it2++;
    }
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        cin>>temp;
        it1 = psa.upper_bound(temp);
        it1--;
        cout<<(*it1).second<<"\n";
    }
}
