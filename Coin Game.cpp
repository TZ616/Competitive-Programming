/*
https://dmoj.ca/problem/ccc12s4
*/
#include <bits/stdc++.h>

using namespace std;

unordered_map<string, bool> m;
deque<pair<string, int>> dq;
int arr[8];
const int MAX = 2e9;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, in, a;
    string s, target, temp;
    cin>>n;
    while (n != 0)
    {
        dq.clear();
        m.clear();
        s = " ";
        target = " ";
        for (int i = 1; i <= n; i++)
        {
            cin>>in;
            s+=to_string(in);
            target+=to_string(i);
        }
        temp = s;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (temp[j]-'0' == i)
                {
                    s[i] = j+'0';
                    break;
                }
            }
        }
        dq.push_back({s, 0});
        m[s] = true;
        while (!dq.empty())
        {
            s = dq.front().first;
            a = dq.front().second;
            dq.pop_front();
            if (s == target)
            {
                break;
            }
            for (int i = 1; i <= n; i++)
            {
                arr[i] = MAX;
            }
            for (int i = 1; i <= n; i++)
            {
                arr[s[i]-'0'] = min(i, arr[s[i]-'0']); 
            }
            for (int i = 2; i <= n; i++)
            {
                if (i-1 > 0 && arr[i] < arr[i-1])
                {
                    temp = s;
                    temp[arr[i]] = (i-1)+'0';
                    if (m.find(temp) == m.end())
                    {
                        m[temp] = true;
                        dq.push_back({temp, a+1});
                    }
                }
            }
            for (int i = 1; i < n; i++)
            {
                if (arr[i] < arr[i+1])
                {
                    temp = s;
                    temp[arr[i]] = (i+1)+'0';
                    if (m.find(temp) == m.end())
                    {
                        m[temp] = true;
                        dq.push_back({temp, a+1});
                    }
                }
            }
        }
        if (s == target)
        {
            cout<<a<<"\n";
        }
        else
        {
            cout<<"IMPOSSIBLE\n";
        }
        cin>>n;
    }
}
