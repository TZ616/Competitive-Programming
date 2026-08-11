/*
https://dmoj.ca/problem/acc5p5
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> arr[1000001];
int dp[1000001];

void dfs(int cur)
{
    vector<int> v;
    for (int i : arr[cur])
    {
        dfs(i);
        v.push_back(dp[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    int maxi = 0;
    for (int i : v)
    {
        if (i > maxi)
        {
            dp[cur]+=i-maxi;
            maxi = i;
        }
        maxi--;
    }
    if (maxi == 0)
    {
        dp[cur]++;
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, in;
    cin>>n;
    for (int i = 2; i <= n; i++)
    {
        cin>>in;
        arr[in].push_back(i);
    }
    dfs(1);
    cout<<dp[1]<<"\n";
}
