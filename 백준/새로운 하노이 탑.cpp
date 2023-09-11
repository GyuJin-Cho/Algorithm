#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>
#include <array>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    array<string, 3> s;
    for (int i = 0; i < 3; i++) 
    {
        int cnt;
        cin >> cnt;
        if (cnt > 0) 
        {
            cin >> s[i];
        }
        else {
            s[i] = "";
        }
    }
    int cnt[3] = { 0, 0, 0 };
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < s[i].length(); j++)
        {
            cnt[s[i][j] - 'A'] += 1;
        }
    }
    map<array<string, 3>, int> d;
    queue<array<string, 3>> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) 
    {
        array<string,3> now = q.front();
        q.pop();
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (i == j) 
                    continue;
                if (now[i].length() == 0)
                    continue;
                array<string, 3> next(now);
                next[j].push_back(next[i].back());
                next[i].pop_back();
                if (d.count(next) == 0) 
                {
                    d[next] = d[now] + 1;
                    q.push(next);
                }
            }
        }
    }
    array<string, 3> ans;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < cnt[i]; j++) 
        {
            ans[i] += (char)('A' + i);
        }
    }
    cout << d[ans];
    return 0;
}