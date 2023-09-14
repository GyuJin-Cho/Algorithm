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

using namespace std;
int n = 3;
int m = 3;
int a[100][100];
int main()
{
    int r, c, k;
    cin >> r >> c >> k;
    r -= 1;
    c -= 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }
    if (a[r][c] == k) 
    {
        cout << 0 << '\n';
        return 0;
    }
    for (int t = 1; t <= 100; t++) 
    {
        if (n >= m) 
        {
            int mm = m;
            for (int i = 0; i < n; i++)
            {
                map<int, int> d;
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] == 0) 
                        continue;
                    d[a[i][j]] += 1;
                }
                vector<pair<int, int>> v;
                for (auto& p : d) 
                {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());
                int l = min((int)v.size(), 50);
                for (int j = 0; j < l; j++) 
                {
                    a[i][j * 2] = v[j].second;
                    a[i][j * 2 + 1] = v[j].first;
                }
                for (int j = l * 2; j < 100; j++) 
                {
                    a[i][j] = 0;
                }
                if (mm < (int)v.size() * 2)
                {
                    mm = (int)v.size() * 2;
                }
            }
            m = mm;
        }
        else 
        {
            int nn = n;
            for (int j = 0; j < m; j++) 
            {
                map<int, int> d;
                for (int i = 0; i < n; i++) 
                {
                    if (a[i][j] == 0) continue;
                    d[a[i][j]] += 1;
                }
                vector<pair<int, int>> v;
                for (auto& p : d) 
                {
                    v.push_back(make_pair(p.second, p.first));
                }
                sort(v.begin(), v.end());
                int l = min((int)v.size(), 50);
                for (int i = 0; i < l; i++) 
                {
                    a[i * 2][j] = v[i].second;
                    a[i * 2 + 1][j] = v[i].first;
                }
                for (int i = l * 2; i < 100; i++)
                {
                    a[i][j] = 0;
                }
                if (nn < (int)v.size() * 2) {
                    nn = (int)v.size() * 2;
                }
            }
            n = nn;
        }
        if (a[r][c] == k) 
        {
            cout << t;
            return 0;
        }
    }
    cout << -1;
    return 0;
}