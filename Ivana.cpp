/*
https://dmoj.ca/problem/coci06c5p5
*/
#include <bits/stdc++.h>

using namespace std;

int dp[101][101], psa[101];
vector<int> v;

int recurse(int l, int r)
{
    if (l > r)
    {
        return 0;
    }
    if (dp[l][r] != -1)
    {
        return dp[l][r];
    }
    dp[l][r] = max(psa[r]-psa[l-1]-recurse(l+1, r), psa[r]-psa[l-1]-recurse(l, r-1));
    return dp[l][r];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, in, ans = 0;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>in;
        v.push_back(in);
        psa[i] = in%2;
        psa[i]+=psa[i-1];
    }
    for (int i = 0; i < n; i++)
    {
        memset(dp, -1, sizeof(dp));
        for (int j = 1; j <= n; j++)
        {
            dp[j][j] = psa[j]-psa[j-1];
        }
        if ((psa[n]-recurse(2, n))*2 > psa[n])
        {
            ans++;
        }
        v.push_back(v.front());
        v.erase(v.begin());
        for (int j = 1; j <= n; j++)
        {
            psa[j] = v[j-1]%2;
            psa[j]+=psa[j-1];
        }
    }
    cout<<ans<<"\n";
}
