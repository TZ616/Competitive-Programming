/*
https://dmoj.ca/problem/mmcc15p1
*/
#include "inaho.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> arr[500001];
int height[500001], numSets[500001];
stack<pair<bool, pair<int, int>>> s;

int findS(int x)
{
    if (arr[x].back() != x)
    {
        return findS(arr[x].back());
    }
    return x;
}

void Init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        arr[i].push_back(i);
        height[i] = 1;
        numSets[i] = 1;
    }
}

void AddEdge(int u, int v)
{
    int t1 = findS(u), t2 = findS(v);
    if (t1 == t2)
    {
        s.push({1, {u, v}});
        return;
    }
    if (height[t2] > height[t1])
    {
        swap(t1, t2);
    }
    numSets[t1]+=numSets[t2];
    arr[t2].push_back(t1);
    if (height[t1] == height[t2])
    {
        height[t1]++;
    }
    s.push({0, {t1, t2}});
}

void RemoveLastEdge()
{
    if (s.top().first)
    {
        s.pop();
        return;
    }
    int t1 = s.top().second.first, t2 = s.top().second.second;
    arr[t2].pop_back();
    numSets[t1]-=numSets[t2];
    s.pop();
} 

int GetSize(int u)
{
    return numSets[findS(u)];
}
