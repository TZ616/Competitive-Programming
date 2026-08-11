/*
https://dmoj.ca/problem/coci17c6p3
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
vector<pair<int, long long>> arr[26][26];

int pascal[2000][2000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 2000; i++)
    {
        pascal[i][0] = 1;
        pascal[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
            pascal[i][j]%=MOD;
        }
    }
    string s, s1;
    int q, in;
    long long ans;
    cin>>s;
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            arr[i][j].push_back({0, 0});
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i+1; j < s.length(); j++)
        {
            if (arr[s[i]-'a'][s[j]-'a'].back().first == i)
            {
                arr[s[i]-'a'][s[j]-'a'].back().second++;
            }
            else
            {
                arr[s[i]-'a'][s[j]-'a'].push_back({i, 1});
            }
        }
    }
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        ans = 0;
        cin>>in>>s1;
        in-=2;
        for (pair<int, long long> j : arr[s1[0]-'a'][s1[1]-'a'])
        {
            ans+=j.second*pascal[j.first][in];
            ans%=MOD;
        }
        cout<<ans<<"\n";
    }
}
