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
int a[50][50];
int b[50][50];
int n, m;
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };
void go(int sx, int sy, int z)
{
    int prev = 0;
    int x = sx;
    int y = sy + 1;
    int k = 0;
    while (true) 
    {
        if (x == sx && y == sy)
            break;
        swap(prev, a[x][y]);
        x += dx[k];
        y += dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m) 
        {
            x -= dx[k];
            y -= dy[k];
            k += z;
            k %= 4;
            x += dx[k];
            y += dy[k];
        }
    }
}
int main()
{
    int t;
    cin >> n >> m >> t;
    int x, y;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
            if (a[i][j] == -1) 
            {
                x = i;
                y = j;
            }
        }
    }
    x -= 1;
    while (t--) 
    {
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (a[i][j] <= 0) continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) 
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) 
                    {
                        cnt += 1;
                    }
                }
                if (cnt > 0) 
                {
                    int val = a[i][j] / 5;
                    for (int k = 0; k < 4; k++) 
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] >= 0) {
                            b[nx][ny] += val;
                        }
                    }
                    a[i][j] = a[i][j] - cnt * val;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++) 
            {
                if (a[i][j] == -1) 
                    continue;
                a[i][j] += b[i][j];
                b[i][j] = 0;
            }
        }
        go(x, y, 1);
        go(x + 1, y, 3);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (a[i][j] >= 0) 
            {
                ans += a[i][j];
            }
        }
    }
    cout << ans;
    return 0;
}
