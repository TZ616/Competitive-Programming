/*
https://dmoj.ca/problem/crci07p3
*/
#include <bits/stdc++.h>

using namespace std;

long long arr[100][6];

long long calc(long long a, long long b, long long c, long long d, long long e)
{
    long long cur_min = 1e18;
    for (int i = 0; i < a; i++)
    {
        if (d*i > a)
        {
            cur_min = min(cur_min, e*i);
            break;
        }
        cur_min = min(cur_min, (long long)(e*i+ceil((double)(a-d*i)/b)*c));
    }
    return cur_min;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n, m, bot = 1, mid, top = 100000, cost, temp;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin>>arr[i][j];
        }
    }
    while (top > bot)
    {
        cost = 0;
        mid = (top+bot)/2;
        for (int i = 0; i < n; i++)
        {
            temp = arr[i][0]*mid-arr[i][1];
            if (temp <= 0)
            {
                continue;
            }
            cost+=calc(temp, arr[i][2], arr[i][3], arr[i][4], arr[i][5]);
            if (cost > m)
            {
                break;
            }
        }
        if (cost > m)
        {
            top = mid;
        }
        else
        {
            bot = mid+1;
        }
    }
    cout<<bot-1<<"\n";
}
