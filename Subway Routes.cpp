/*
https://dmoj.ca/problem/subway
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> arr[400001];
vector<int> v;
bool vis[400001];
int d[2];
unordered_map<int, int> m;
int n, a, b, s, w, x = 0, y, z = 0, p = 0;

void dfs1(int cur, int length)
{
    if (length > x)
    {
        w = cur;
        x = length;
    }
    vis[cur] = true;
    for (int i : arr[cur])
    {
        if (!vis[i])
        {
            dfs1(i, length+1);
        }
    }
}

void dfs2(int cur, int length)
{
    if (length > z)
    {
        z = length;
        y = cur;
    }
    vis[cur] = false;
    for (int i : arr[cur])
    {
        if (vis[i])
        {
            dfs2(i, length+1);
        }
    }
}

bool dfs3(int cur)
{
    vis[cur] = true;
    if (cur == y)
    {
        return true;
    }
    for (int i : arr[cur])
    {
        v.push_back(i);
        if (!vis[i] && dfs3(i))
        {
            return true;
        }
        v.pop_back();
    }
    return false;
}

void dfs4(int cur, int length)
{
    vis[cur] = true;
    if (length == 0)
    {
        s++;
        return;
    }
    for (int i : arr[cur])
    {
        if (!vis[i])
        {
            dfs4(i, length-1);
        }
    }
}

void dfs5(int cur, int length, int belong)
{
    if (length == 0)
    {
        s++;
        m[belong]++;
        return;
    }
    vis[cur] = true;
    if (length == z/2)
    {
        for (int i : arr[cur])
        {
            if (!vis[i])
            {
                dfs5(i, length-1, i);
            }
        }
    }
    else
    {
        for (int i : arr[cur])
        {
            if (!vis[i])
            {
                dfs5(i, length-1, belong);
            }
        }
    }
}

void ini()
{
    for (int i = 1; i <= n; i++)
    {
        vis[i] = false;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0, temp;
    cin>>n;
    for (int i = 1; i < n; i++)
    {
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(w, 1);
    v.push_back(w);
    dfs3(w);
    ini();
    if (v.size()%2)
    {
        dfs5(v[v.size()/2], z/2, 0);
        for (pair<int, int> i : m)
        {
            temp = i.second;
            temp*=(s-i.second);
            ans+=temp;
        }
        ans/=2;
    }
    else
    {
        vis[v[v.size()/2-1]] = true;
        dfs4(v[v.size()/2], z/2-1);
        ans = s;
        s = 0;
        ini();
        vis[v[v.size()/2]] = true;
        dfs4((v[v.size()/2-1]), z/2-1);
        ans*=s;
    }
    cout<<ans<<"\n";
}
