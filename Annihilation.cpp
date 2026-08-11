/*
https://dmoj.ca/problem/dmopc15c3p5
*/
#include <bits/stdc++.h>

using namespace std;

long long arr[36], ans;
map<long long, long long> m1, m2;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    map<long long, long long>::iterator it;
    cin>>n>>m;
    for (int i = 0; i < n+m; i++)
    {
        cin>>arr[i];
        if (i >= n)
        {
            arr[i]*=-1;
        }
    }
    m1[0] = 1;
    m2[0] = 1;
    for (int i = 0; i < (m+n)/2; i++)
    {
        if (arr[i] > 0)
        {
            it = m1.end();
            it--;
            while (it != m1.begin())
            {
                m1[(*it).first+arr[i]]+=(*it).second;
                it--;
            }
            m1[(*m1.begin()).first+arr[i]]+=(*m1.begin()).second;
        }
        else
        {
            it = m1.begin();
            while (it != m1.end())
            {
                m1[(*it).first+arr[i]]+=(*it).second;
                it++;
            }
        }
    }
    for (int i = (m+n)/2; i < m+n; i++)
    {
        if (arr[i] > 0)
        {
            it = m2.end();
            it--;
            while (it != m2.begin())
            {
                m2[(*it).first+arr[i]]+=(*it).second;
                it--;
            }
            m2[(*m2.begin()).first+arr[i]]+=(*m2.begin()).second;
        }
        else
        {
            it = m2.begin();
            while (it != m2.end())
            {
                m2[(*it).first+arr[i]]+=(*it).second;
                it++;
            }
        }
    }
    ans = max(m1[0], m2[0])-1;
    m1.erase(0);
    m2.erase(0);
    for (pair<long long, long long> i : m1)
    {
        ans+=m2[-i.first]*i.second;
    }
    cout<<ans<<"\n";
}
