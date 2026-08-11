/*
https://dmoj.ca/problem/rte16s2
*/
#include <bits/stdc++.h>

using namespace std;

string arr[4], s;
set<pair<int, int>> dp[2501];
pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool check (int index, int num)
{
    int cur = 0;
    for (int i = index-arr[num].length()+1; i <= index; i++)
    {
        if (arr[num][cur] != s[i])
        {
            return false;
        }
        cur++;
    }
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    dp[0].insert({0, 0});
    for (int i = 0; i < 4; i++)
    {
        cin>>arr[i];
    }
    cin>>s;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i-arr[j].length() >= 0 && check(i-1, j))
            {
                for (pair<int, int> k : dp[i-arr[j].length()])
                {
                    dp[i].insert({k.first+dir[j].first, k.second+dir[j].second});
                }
            }
        }
    }
    cout<<dp[s.length()].size()<<"\n";
}
