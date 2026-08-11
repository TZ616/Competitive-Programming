/*
https://dmoj.ca/problem/aac2p4
*/
#include <bits/stdc++.h>

using namespace std;

int arr[600], out[600];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t, n, pos1, pos2;
    bool draw;
    cin>>t;
    for (int asdf = 0; asdf < t; asdf++)
    {
        draw = true;
        cin>>n;
        if (n%2)
        {
            draw = false;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        if (arr[0] != arr[n-1])
        {
            draw = false;
        }
        if (draw)
        {
            cout<<-1<<'\n';
            continue;
        }
        cout<<arr[n-1];
        pos1 = 0;
        pos2 = n-2;
        for (int i = 0; i < n; i++)
        {
            if (pos1 > pos2)
            {
                break;
            }
            if (i%2)
            {
                out[i] = arr[pos2];
                pos2--;
                if (pos2 < pos1)
                {
                    break;
                }
                out[n-i-2] = arr[pos2];
                pos2--;
            }
            else
            {
                out[i] = arr[pos1];
                pos1++;
                if (pos1 > pos2)
                {
                    break;
                }
                out[n-i-2] = arr[pos1];
                pos1++;
            }
        }
        for (int i = 0; i < n-1; i++)
        {
            cout<<" "<<out[i];
        }
        cout<<"\n";
    }
}
