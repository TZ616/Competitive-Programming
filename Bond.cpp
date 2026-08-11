/*
https://dmoj.ca/problem/coci06c1p5
*/
#include <bits/stdc++.h>

using namespace std;

vector<int> v[2];
double dp[1048576];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    double a;
    cin>>n;
    v[0].push_back(0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        temp = i%2;
        for (int j = 0; j < n; j++)
        {
            cin>>a;
            a/=100;
            for (int k : v[temp])
            {
                if (dp[k]*a > dp[k|(1<<j)])
                {
                    dp[k|(1<<j)] = dp[k]*a;
                    v[!temp].push_back(k|(1<<j));
                }
            }
        }
        v[temp].clear();
    }
    printf("%.10f\n", dp[(1<<n)-1]*100);
}
