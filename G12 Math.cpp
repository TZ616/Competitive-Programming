/*
https://dmoj.ca/problem/dmopc19c6p4
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
long long arr[500001];
const int CONVERT = 1e9, ADD = 500000;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    Tree<long long> tree;
    int n, q;
    long long a, b, c, d;
    cin>>n>>q;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = ADD;
        tree.insert(arr[i]*CONVERT+i);
    }
    for (int i = 0; i < q; i++)
    {
        cin>>a;
        if (a == 1)
        {
            cin>>b;
            tree.erase(arr[b]*CONVERT+b);
            arr[b]++;
            tree.insert(arr[b]*CONVERT+b);
        }
        else if (a == 2)
        {
            cin>>b;
            tree.erase(arr[b]*CONVERT+b);
            arr[b]--;
            tree.insert(arr[b]*CONVERT+b);
        }
        else
        {
            cin>>b>>c>>d;
            d+=ADD;
            cout<<tree.order_of_key(d*CONVERT+c+1)-tree.order_of_key(d*CONVERT+b)<<"\n";
        }
    }
}
