/*
https://dmoj.ca/problem/smac08c1p3
*/
#include <bits/stdc++.h>

using namespace std;

multiset<int> s;
int dp[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin>>n>>d;
    cin>>dp[1];
    s.insert(dp[1]);
    for (int i = 2; i <= n; i++)
    {
        cin>>dp[i];
        if (i-d-1 > 0)
        {
            s.erase(s.find(dp[i-d-1]));
        }
        dp[i]+=(*s.begin());
        s.insert(dp[i]);
    }
    cout<<dp[n]<<"\n";
}
