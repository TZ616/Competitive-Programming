/*
https://dmoj.ca/problem/mnyc16p6
*/
#include <bits/stdc++.h>

using namespace std;

map<string, int> m;
int n, bit[100001];

int calc(string s)
{
    int sum = 0;
    for (char i : s)
    {
        sum+=i-'`';
    }
    return sum;
}


void update(int pos, int add)
{
    while (pos <= n)
    {
        bit[pos]+=add;
        pos+=pos&-pos;
    }
}

int query(int pos)
{
    int sum = 0;
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
    int temp1, temp2;
    char a;
    string s1, s2;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if (a == 'A')
        {
            cin>>s1;
            if (m.find(s1) != m.end())
            {
                cout<<"Can't add "<<s1<<"\n";
            }
            else
            {
                m[s1] = m.size()+1;
                update(m.size(), calc(s1));
            }
        }
        else if (a == 'S')
        {
            cin>>s1>>s2;
            temp1 = m[s1];
            temp2 = m[s2];
            update(temp1, calc(s2)-calc(s1));
            update(temp2, calc(s1)-calc(s2));
            m[s1] = temp2;
            m[s2] = temp1;
        }
        else if (a == 'M')
        {
            cin>>s1>>s2;
            temp1 = m[s1];
            temp2 = m[s2];
            if (temp1 > temp2)
            {
                swap(temp1, temp2);
            }
            cout<<query(temp2)-query(temp1-1)<<"\n";
        }
        else if (a == 'R')
        {
            cin>>s1>>s2;
            m[s2] = m[s1];
            update(m[s1], calc(s2)-calc(s1));
            m.erase(s1);
        }
        else
        {
            cout<<m.size()<<"\n";
        }
    }
}
