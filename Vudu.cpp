/*
https://dmoj.ca/problem/coci15c2p5
*/
#include <bits/stdc++.h>

using namespace std;

long long psa[1000001], arr[1000001];
int bit[1000002], n, p;

void update(int pos)
{
    while (pos <= 1000001)
    {
        bit[pos]++;
        pos+=pos&-pos;
    }
}

long long query(int pos)
{
    long long sum = 0;
    while (pos > 0)
    {
        sum+=bit[pos];
        pos-=pos&-pos;
    }
    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long ans = 0, temp;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>psa[i];
    }
    cin>>p;
    for (int i = 1; i <= n; i++)
    {
        psa[i]-=p;
        psa[i]+=psa[i-1];
        arr[i] = psa[i];
    }
    sort(arr, arr+n+1);
    update((lower_bound(arr, arr+n+1, 0)-arr)+1);
    for (int i = 1; i <= n; i++)
    {
        temp = (lower_bound(arr, arr+n+1, psa[i])-arr)+1;
        ans+=query(temp);
        update(temp);
    }
    cout<<ans<<"\n";
}
