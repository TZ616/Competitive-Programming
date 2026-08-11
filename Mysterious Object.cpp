/*
https://dmoj.ca/problem/art7
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
int dp[100000][2][2][2];
string s;

int recurse(int size, bool same, int zeroes, bool ones)
{
    if (zeroes >= 2)
    {
        return 0;
    }
    if ((size == s.length()) && (zeroes == 1) && ones)
    {
        return 1;
    }
    else if (size == s.length())
    {
        return 0;
    }
    if (dp[size][same][zeroes][ones] != -1)
    {
        return dp[size][same][zeroes][ones];
    }
    dp[size][same][zeroes][ones] = 0;
    int temp = (same?s[size]-'0':9);
    for (int i = 0; i <= temp; i++)
    {
        dp[size][same][zeroes][ones]+=recurse(size+1, (same&&(i==temp)), zeroes+(ones&&(i==0)), (ones||(i==1)));
        dp[size][same][zeroes][ones]%=MOD;
    }
    return dp[size][same][zeroes][ones];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>s;
    cout<<recurse(0, 1, 0, 0)<<"\n";
}
