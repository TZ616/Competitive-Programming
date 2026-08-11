/*
https://dmoj.ca/problem/dmopc16c4p6
*/
#include <bits/stdc++.h>

#define int long long

using namespace std;

deque<pair<int, int>> dq;
long long arr[1000001];

signed main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, q, in, a, b;
    long long temp, temp1;
    cin>>n>>q;
    dq.push_front({0, 0});
    for (int i = 1; i <= n; i++)
    {
        cin>>in;
        while (in <= dq.front().first)
        {
            temp = dq.front().second;
            temp1 = dq.front().first;
            dq.pop_front();
            arr[temp1]+=(temp-dq.front().second)*(i-temp);
        }
        dq.push_front({in, i});
    }
    while (dq.size() > 1)
    {
        temp = dq.front().second;
        temp1 = dq.front().first;
        dq.pop_front();
        arr[temp1]+=(temp-dq.front().second)*(n+1-temp);
    }
    for (int i = 1; i <= 1000000; i++)
    {
        arr[i]+=arr[i-1];
    }
    for (int i = 0; i < q; i++)
    {
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
}
