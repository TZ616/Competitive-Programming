/*
https://dmoj.ca/problem/fibonacci2
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
vector<vector<long long>> arr[100001];
string s;

vector<vector<long long>> calc(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> ans;
    vector<long long> v;
    ans.clear();
    long long temp;
    for (int i = 0; i < a.size(); i++)
    {
        v.clear();
        for (int j = 0; j < a.size(); j++)
        {
            temp = 0;
            for (int k = 0; k < a.size(); k++)
            {
                temp+=a[i][k]*b[k][j];
                temp%=MOD;
            }
            v.push_back(temp);
        }
        ans.push_back(v);
    }
    return ans;
}

long long ans ()
{
    vector<vector<long long>> ori = {{1, 1}, {1, 0}};
    vector<vector<long long>> ans = {{1, 0}, {0, 1}};
    vector<vector<long long>> f = {{1, 0}, {0, 1}};
    arr[0] = {{1, 1}, {1, 0}};
    int temp = s[0]-'0';
    while (temp > 0)
    {
        if (temp&1)
        {
            ans = calc(ans, ori);
        }
        ori = calc(ori, ori);
        temp>>=1;
    }
    f = calc(f, ans);
    for (int i = 1; i < s.length(); i++)
    {
        ori = arr[i-1];
        ans = {{1, 0}, {0, 1}};
        temp = 10;
        while (temp > 0)
        {
            if (temp&1)
            {
                ans = calc(ans, ori);
            }
            ori = calc(ori, ori);
            temp>>=1;
        }
        arr[i] = ans;
        ori = arr[i];
        ans = {{1, 0}, {0, 1}};
        temp = s[i]-'0';
        while (temp > 0)
        {
            if (temp&1)
            {
                ans = calc(ans, ori);
            }
            ori = calc(ori, ori);
            temp>>=1;
        }
        f = calc(ans, f);
    }
    return f[0][1]%MOD;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    reverse(s.begin(), s.end());
    cout<<ans()<<"\n";
}
