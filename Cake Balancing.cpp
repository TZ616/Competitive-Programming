/*
https://dmoj.ca/problem/year2016p6
*/
#include <bits/stdc++.h>

using namespace std;

int arrl[1<<10], arrr[1<<10], dp[1<<10][1<<10], w;
multimap<int, int, greater<int>> ml, mr;

int recurse(int l, int r)
{
    if (l == 0 && r == 0)
    {
        return 0;
    }
    if (dp[l][r] != 0)
    {
        return dp[l][r];
    }
    dp[l][r] = 2e9;
    map<int, int>::iterator it= ml.lower_bound(arrl[l]-arrr[r]+w);
    while (it != ml.end() && ((*it).second|l) != l)
    {
        it++;
    }
    if (it != ml.end())
    {
        dp[l][r] = recurse(l^((*it).second), r)+1;
    }
    map<int, int>::iterator it1 = mr.lower_bound(arrr[r]-arrl[l]+w);
    while (it1 != mr.end() && ((*it1).second|r) != r)
    {
        it1++;
    }
    if (it1 != mr.end())
    {
        dp[l][r] = min(dp[l][r], recurse(l, r^((*it1).second)))+1;
    }
    return dp[l][r];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int l, r, in;
    cin>>l>>r>>w;
    ml.insert({0, 0});
    mr.insert({0, 0});
    for (int i = 0; i < l; i++)
    {
        cin>>in;
        for (pair<int, int> j : ml)
        {
            ml.insert({j.first+in, j.second|(1<<i)});
            arrl[j.second|(1<<i)] = j.first+in;
        }
    }
    for (int i = 0; i < r; i++)
    {
        cin>>in;
        for (pair<int, int> j : mr)
        {
            mr.insert({j.first+in, j.second|(1<<i)});
            arrr[j.second|(1<<i)] = j.first+in;
        }
    }
    ml.erase(0);
    mr.erase(0);
    cout<<recurse((1<<l)-1, (1<<r)-1)<<"\n";
}
