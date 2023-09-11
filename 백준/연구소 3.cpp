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
using namespace std;
int a[100][100];
int d[100][100];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
vector<pair<int, int>> candi;
int ans = -1;
void BFS()
{
    memset(d, -1, sizeof(d));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 3)
            {
                q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }
    while (!q.empty())
    {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (a[nx][ny] != 1 && d[nx][ny] == -1)
                {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                if (d[i][j] == -1)
                    return;
                if (cur < d[i][j])
                    cur = d[i][j];
            }
        }
    }
    if (ans == -1 || ans > cur)
    {
        ans = cur;
    }
}
void DFS(int index, int cnt)
{
    if (index == candi.size())
    {
        if (cnt == m)
        {
            BFS();
        }
    }
    else
    {
        int x, y;
        tie(x, y) = candi[index];
        a[x][y] = 3;
        DFS(index + 1, cnt + 1);
        a[x][y] = 2;
        DFS(index + 1, cnt);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 2)
            {
                candi.push_back(make_pair(i, j));
            }
        }
    }
    DFS(0, 0);
    cout << ans;
    return 0;
}
