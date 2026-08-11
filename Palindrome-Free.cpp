/*
https://dmoj.ca/problem/btoi13p2
*/
#include <bits/stdc++.h>

using namespace std;

long long dp[18][2][11][11][2][2];
string s[2];

long long recurse(int size, bool same, int first, int second, bool lead, int cur)
{
    if (size == s[cur].length())
    {
        return 1;
    }
    if (dp[size][same][first][second][lead][cur] != -1)
    {
        return dp[size][same][first][second][lead][cur];
    }
    dp[size][same][first][second][lead][cur] = 0;
    int temp = (same?s[cur][size]-'0':9);
    for (int i = 0; i <= temp; i++)
    {
        if (i != first && i != second)  
        {
            dp[size][same][first][second][lead][cur]+=recurse(size+1, same&&(i==temp), second, (lead&&(i==0)?10:i), lead&&(i==0), cur);
        }
    }
    return dp[size][same][first][second][lead][cur];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    long long in;
    cin>>in>>s[1];
    s[0] = to_string(in-1);
    cout<<recurse(0, 1, 10, 10, 1, 1)-recurse(0, 1, 10, 10, 1, 0)<<"\n";
}
