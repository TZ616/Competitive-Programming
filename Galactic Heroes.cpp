/*
https://dmoj.ca/problem/noi02p1
*/
#include <bits/stdc++.h>

using namespace std;

int p[30001], numSets[30001], pos[30001];

int findS(int x)
{
    int temp = p[x];
    bool z = p[x]==p[p[x]];
    if (p[x] == x)
    {
        return x;
    }
    p[x] = findS(p[x]);
    if (!z)
    {
        pos[x]=pos[temp]+pos[x]-1;
    }
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
    p[x] = y;
    pos[x] = numSets[y]+1;
    numSets[y]+=numSets[x];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 1; i < 30001; i++)
    {
        p[i] = i;
        numSets[i] = 1;
        pos[i] = 1;
    }
    int n, a, b;
    char c;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>c>>a>>b;
        if (c == 'M')
        {
            unionS(a, b);
        }
        else
        {
            if (sameSet(a, b))
            {
                cout<<abs(pos[a]-pos[b])-1<<"\n";
            }
            else
            {
                cout<<-1<<"\n";
            }
        }
    }
}
