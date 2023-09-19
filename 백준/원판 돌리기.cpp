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
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void go(vector<vector<int>>& a, int x, int d, int k)
{
    if (d == 0) 
    {
        rotate(a[x].rbegin(), a[x].rbegin() + k, a[x].rend());
    }
    else 
    { 
        rotate(a[x].begin(), a[x].begin() + k, a[x].end());
    }
}
bool check(vector<vector<int>>& a)
{
    int n = (int)a.size() - 1;
    int m = a[1].size();
    vector<vector<bool>> d(n + 1, vector<bool>(m, false));
    bool ok = false;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] == 0) continue;
            if (a[i][j] == a[i][(j + 1) % m]) 
            {
                d[i][j] = d[i][(j + 1) % m] = true;
            }
            if (i + 1 <= n && a[i][j] == a[i + 1][j])
            {
                d[i][j] = d[i + 1][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (d[i][j]) {
                ok = true;
                a[i][j] = 0;
            }
        }
    }
    return ok;
}
void adjust(vector<vector<int>>& a)
{
    int n = (int)a.size() - 1;
    int m = a[1].size();
    long long sum = 0;
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] == 0) continue;
            sum += a[i][j];
            cnt += 1;
        }
    }
    if (cnt == 0LL) return;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] == 0) continue;
            if (sum < (long long)a[i][j] * cnt) 
            {
                a[i][j] -= 1;
            }
            else if (sum > (long long)a[i][j] * cnt)
            {
                a[i][j] += 1;
            }
        }
    }
}
int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<int>> a(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    while (t--) 
    {
        int x, d, k;
        cin >> x >> d >> k;
        for (int y = x; y <= n; y += x) 
        {
            go(a, y, d, k);
        }
        bool ok = check(a);
        if (ok == false)
        {
            adjust(a);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            ans += a[i][j];
        }
    }
    cout << ans << '\n';
    return 0;
}