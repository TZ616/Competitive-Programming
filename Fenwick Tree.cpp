/*
https://dmoj.ca/problem/olyrim2
*/
#include <bits/stdc++.h>

using namespace std;

int bit[30][100001], arr[100001], n, q, a, b, in;

void update(int b_pos, int pos, int num)
{
    while (pos <= n)
    {
        bit[b_pos][pos]+=num;
        pos+=pos&-pos;
    }
}

long long query(int b_pos, int pos)
{
    long long sum = 0;
    while (pos > 0)
    {
        sum+=bit[b_pos][pos];
        pos-=pos&-pos;
    }
    return sum;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long ans, temp;
    cin>>n>>q;
    for (int i = 1; i <= n; i++)
    {
        cin>>arr[i];
        for (int j = 0; j < 30; j++)
        {
            update(j, i, (arr[i]>>j)&1);
        }
    }
    for (int i = 0; i < q; i++)
    {
        cin>>in>>a>>b;
        if (in == 1)
        {
            for (int j = 0; j < 30; j++)
            {
                update(j, a, ((b>>j)&1)-((arr[a]>>j)&1));
            }
            arr[a] = b;
        }
        else if (in == 2)
        {
            ans = 0;
            for (int j = 0; j < 30; j++)
            {
                temp = query(j, b)-query(j, a-1);
                ans+=(temp*(b-a+1-temp)+temp*(temp-1)/2)*(1<<j);
            }
            cout<<ans<<"\n";
        }
        else if (in == 3)
        {
            ans = 0;
            for (int j = 0; j < 30; j++)
            {
                temp = query(j, b)-query(j, a-1);
                ans+=temp*(temp-1)/2*(1<<j);
            }
            cout<<ans<<"\n";
        }
        else
        {
            ans = 0;
            for (int j = 0; j < 30; j ++)
            {
                temp = query(j, b)-query(j, a-1);
                ans+=temp*(b-a+1-temp)*(1<<j);
            }
            cout<<ans<<"\n";
        }
    }
}
