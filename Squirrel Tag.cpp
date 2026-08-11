/*
https://dmoj.ca/problem/wac4p3
*/
#include <bits/stdc++.h>

using namespace std;

double dp[1<<16][16];
double arr[16][4];
const double ep = 1e-9;
long long n, s;

double calc (double a, double b, double c, double d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

double recurse(int vis, int cur)
{
    if (vis == 1)
    {
        return 0;
    }
    else if (cur == 0)
    {
        return 1e15;
    }
    else if (dp[vis][cur] != 0)
    {
        return dp[vis][cur];
    }
    double temp, bot, top, mid;
    dp[vis][cur] = 1e15;
    for (int i = 0; i <= n; i++)
    {
        if (i != cur && (vis&(1<<i)) != 0)
        {
            temp = recurse(vis^(1<<cur), i);
            if (temp >= 1e15)
            {
                continue;
            }
            bot = 0;
            top = 1e15;
            int counter = 100;
            while (top > bot+ep && counter--)
            {
                mid = (bot+top)/2;
                if (calc(arr[cur][2]*(mid+temp)+arr[cur][0], arr[cur][3]*(mid+temp)+arr[cur][1], arr[i][2]*temp+arr[i][0], arr[i][3]*temp+arr[i][1])/mid > s)
                {
                    bot = mid+ep;
                }
                else
                {
                    top = mid;
                }
            }
            dp[vis][cur] = min(dp[vis][cur], temp+bot);
        }
    }
    return dp[vis][cur];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    double ans = 1e15;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, recurse((1<<(n+1))-1, i));
    }
    printf("%.9f\n", ans);
}
