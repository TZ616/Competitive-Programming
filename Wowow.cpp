/*
https://dmoj.ca/problem/cco10p3
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = __gnu_pbds::tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
int arr[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    Tree<pair<int, int>> tree;
    int n, b, c;
    char a;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if (a == 'N')
        {
            cin>>b>>c;
            arr[b] = c;
            tree.insert({c, b});
        }
        else if (a == 'M')
        {
            cin>>b>>c;
            tree.erase({arr[b], b});
            arr[b] = c;
            tree.insert({c, b});
        }
        else
        {
            cin>>b;
            cout<<(*tree.find_by_order(b-1)).second<<"\n";
        }
    }
}
