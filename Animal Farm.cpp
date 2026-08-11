/*
https://dmoj.ca/problem/ccc10s4
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 102, M = 1001;
int p[N], height[N], numSets[N];
pair<int, pair<int, int>> walls[M][M];
deque<pair<int, int>> dq;
vector<pair<int, pair<int, int>>> v;

void initialize(int n)
{
    for (int i = 1; i <= n+1; i++)
    {
        p[i] = i;
        height[i] = 1;
        numSets[i] = 1;
    }
}

int findS(int x)
{
    if (p[x] == x)
    {
        return x;
    }
    p[x] = findS(p[x]);
    return p[x];
}

bool sameSet(int x, int y)
{
    return findS(x)==findS(y);
}

void unionS(int x, int y)
{
    x = findS(x);
    y = findS(y);
    if (x == y)
    {
        return;
    }
    if (height[y] > height[x])
    {
        swap(y, x);
    }
    p[y] = x;
    if (height[y] == height[x])
    {
        height[x]++;
    }
    numSets[x]+=numSets[y];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, x, first, prev, a, ans1 = 0, ans2 = 0;
    cin>>n;
    initialize(n);
    for (int i = 1; i <= n; i++)
    {
        cin>>x;
        first = 0;
        for (int j = 0; j < x; j++)
        {
            cin>>a;
            if (first == 0)
            {
                first = a;
            }
            else
            {
                dq.push_back({min(a, prev), max(a, prev)});
            }
            prev = a;
        }
        dq.push_back({min(a, first), max(a, first)});
        for (int j = 0; j < x; j++)
        {
            cin>>a;
            walls[dq.front().first][dq.front().second].first = a;
            if (walls[dq.front().first][dq.front().second].second.first == 0)
            {
                walls[dq.front().first][dq.front().second].second.first = i;
                walls[dq.front().first][dq.front().second].second.second = n+1;
            }
            else
            {
                walls[dq.front().first][dq.front().second].second.second = i;
            }
            dq.pop_front();
        }
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = i; j < M; j++)
        {
            if (walls[i][j].first != 0)
            {
                v.push_back(walls[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());
    for (pair<int, pair<int, int>> i : v)
    {
        if (!sameSet(i.second.first, i.second.second))
        {
            unionS(i.second.first, i.second.second);
            ans1+=i.first;
        }
    }
    initialize(n);
    for (pair<int, pair<int, int>> i : v)
    {
        if (i.second.second != n+1 && !sameSet(i.second.first, i.second.second))
        {
            unionS(i.second.first, i.second.second);
            ans2+=i.first;
        }
    }
    cout<<min(ans1, ans2)<<"\n";
}
