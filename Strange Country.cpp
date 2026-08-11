/*
https://dmoj.ca/problem/arc1p5
*/
#include <bits/stdc++.h>

using namespace std;

const int MN = 5001, MK = 10001, MM = 300000;
short int p[MK][MN], height[MK][MN], ans[MM];
vector<pair<pair<int, int>, pair<int, int>>> v;

int findS(int a, int b)
{
    if (p[a][b] == b)
    {
        return b;
    }
    p[a][b] = findS(a, p[a][b]);
    return p[a][b];
}

bool sameSet(int a, int b, int c)
{
    return findS(a, b) == findS(a, c);
}

void unionS(int a, int b, int c)
{
    b = findS(a, b);
    c = findS(a, c);
    if (b == c)
    {
        return;
    }
    if (height[a][b] < height[a][c])
    {
        swap(b, c);
    }
    p[a][c] = b;
    if (height[a][c] == height[a][b])
    {
        height[a][b]++;
    }
}

int binarySearch(int k, int a, int b)
{
    int top = k, bottom = 1, mid;
    while (top > bottom)
    {
        mid = (top+bottom)/2;
        if (sameSet(mid, a, b))
        {
            bottom = mid+1;
        }
        else
        {
            top = mid;
        }
    }
    if (sameSet(top, a, b))
    {
        return -1;
    }
    unionS(top, a, b);
    return top;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, k, a, b, c;
    cin>>n>>m>>k;
    for (short int i = 1; i <= k; i++)
    {
        for (short int j = 1; j <= n; j++)
        {
            p[i][j] = j;
            height[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        v.push_back({{c, i}, {a, b}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < m; i++)
    {
        ans[v[i].first.second] = binarySearch(k, v[i].second.first, v[i].second.second);
    }
    for (int i = 0; i < m; i++)
    {
        cout<<ans[i]<<"\n";
    }
}
