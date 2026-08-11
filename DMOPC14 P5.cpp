/*
https://dmoj.ca/problem/dmopc14c3p5/resubmit/7231451
*/
#include <bits/stdc++.h>

using namespace std;

vector<short int> dp[1<<20];
int arr[51];
bool ac[20];
deque<int> dq;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m, t, x;
    string s;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        ac[i] = true;
        for (int j = 1; j <= m; j++)
        {
            if (s[j-1] == 'X')
            {
                ac[i] = false;
            }
            arr[j]|=((s[j-1]=='X')<<i);
        }
        if (ac[i])
        {
            for (int j = 1; j <= m; j++)
            {
                arr[j]|=(1<<i);
            }
        }
    }
    dq.push_back(0);
    for (int i = 1; i <= m; i++)
    {
        t = dq.size();
        while (t--)
        {
            x = dq.front();
            if ((x|arr[i]) != 0 && dp[x|arr[i]].size() == 0)
            {
                dp[x|arr[i]] = dp[x];
                dp[x|arr[i]].push_back(i);
                dq.push_back(x|arr[i]);
            }
            else if ((x|arr[i]) != 0 && dp[x|arr[i]].size() > dp[x].size()+1)
            {
                dp[x|arr[i]] = dp[x];
                dp[x|arr[i]].push_back(i);
            }
            dq.push_back(x);
            dq.pop_front();
        }
    }
    cout<<dp[(1<<n)-1].size()<<"\n";
    for (short int i : dp[(1<<n)-1])
    {
        cout<<i<<" ";
    }
    cout<<"\n";
}
