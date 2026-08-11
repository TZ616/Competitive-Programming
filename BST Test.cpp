/*
https://dmoj.ca/problem/ds4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
unordered_map<int, int> m1;
const int CONVERT = 1e9;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    Tree<long long> tree;
    long long n, m, last = 0, b, temp;
    char a;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>b;
        if (m1.find(b) == m1.end())
        {
            m1[b] = 1;
        }
        else
        {
            m1[b]++;
        }
        tree.insert(b*CONVERT+m1[b]);
    }
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        b^=last;
        if (a == 'I')
        {
            if (m1.find(b) == m1.end())
            {
                m1[b] = 1;
            }
            else
            {
                m1[b]++;
            }
            tree.insert(b*CONVERT+m1[b]);
        }
        else if (a == 'R')
        {
            if (m1.find(b) != m1.end() && m1[b] >= 1)
            {
                tree.erase(b*CONVERT+m1[b]);
                m1[b]--;
            }
        }
        else if (a == 'S')
        {
            temp = *tree.find_by_order(b-1);
            temp/=CONVERT;
            last = temp;
            cout<<temp<<"\n";
        }
        else
        {
            if (m1.find(b) != m1.end() && m1[b] >= 1)
            {
                temp = tree.order_of_key(b*CONVERT);
                last = temp+1;
                cout<<temp+1<<"\n";
            }
            else
            {
                last = -1;
                cout<<-1<<"\n";
            }
        }
    }
    for (long long i : tree)
    {
        cout<<i/CONVERT<<" ";
    }
    cout<<"\n";
}
