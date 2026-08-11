/*
https://dmoj.ca/problem/vmss15c1p5
*/
#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001]; //num, cost, space
int fruits[1001][1001][10];
pair<int, pair<int, int>> arr[100];
string names[10];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, r, s, a, b, c, cur = 1;
    cin>>n>>r>>s;
    for (int i = 0; i < n; i++)
    {
        cin>>names[i]>>a>>b>>c;
        arr[cur] = {a, {b, c}};
        cur++;
        for (int j = 1; j < 10; j++)
        {
            a*=2;
            b*=2;
            c*=2;
            arr[cur] = {a, {b, c}};
            cur++;
        }
    }
    for (int i = 1; i <= cur; i++)
    {
        for (int j = r; j >= arr[i].second.first; j--)
        {
            for (int k = s; k >= arr[i].second.second; k--)
            {
                if (dp[j-arr[i].second.first][k-arr[i].second.second]+arr[i].first > dp[j][k])
                {
                    for (int l = 0; l < 10; l++)
                    {
                        fruits[j][k][l] = fruits[j-arr[i].second.first][k-arr[i].second.second][l];
                    }
                    fruits[j][k][(i-1)/10]+=pow(2, (i-1)%10);
                    dp[j][k] = dp[j-arr[i].second.first][k-arr[i].second.second]+arr[i].first;
                }
            }
        }
    }
    cout<<dp[r][s]<<"\n";
    for (int i = 0; i < n; i++)
    {
        cout<<names[i]<<" "<<fruits[r][s][i]<<"\n";
    }
}
