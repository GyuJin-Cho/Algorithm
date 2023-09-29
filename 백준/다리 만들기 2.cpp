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
struct Edge
{
    int from, to, cost;
};
int n, m;
int board[10][10];
int group[10][10];
int groups = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<Edge> edges;
int ans = -1;
int a[10][10];
bool check[10];
int bridge[10][10];
void bfs(int x, int y)
{
    groups += 1;
    queue<pair<int, int>> q;
    group[x][y] = groups;
    q.push(make_pair(x, y));
    while (!q.empty()) 
    {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k = 0; k < 4; k++) 
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < m) 
            {
                if (board[nx][ny] == 1 && group[nx][ny] == 0) 
                {
                    q.push(make_pair(nx, ny));
                    group[nx][ny] = groups;
                }
            }
        }
    }
}
void dfs(int x)
{
    for (int y = 1; y <= groups; y++) 
    {
        if (a[x][y] > 0 && check[y] == false) 
        {
            check[y] = true;
            dfs(y);
        }
    }
}
void go(int index, int sum)
{
    if (index == edges.size()) 
    {
        memset(check, false, sizeof(check));
        check[1] = true;
        dfs(1);
        for (int i = 1; i <= groups; i++) 
        {
            if (check[i] == false) return;
        }
        if (ans == -1 || ans > sum) 
        {
            ans = sum;
        }
        return;
    }
    Edge e = edges[index];
    a[e.from][e.to] = a[e.to][e.from] = e.cost;
    go(index + 1, sum + e.cost);
    a[e.from][e.to] = a[e.to][e.from] = 0;
    go(index + 1, sum);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (board[i][j] == 1 && group[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (board[i][j] == 0)
                continue;
            for (int k = 0; k < 4; k++) 
            {
                int len = 0;
                int x = i + dx[k];
                int y = j + dy[k];
                while (0 <= x && x < n && 0 <= y && y < m) 
                {
                    if (board[x][y] == 0) 
                    {
                    }
                    else if (group[x][y] == group[i][j])
                    {
                        break;
                    }
                    else
                    {
                        if (len >= 2)
                        {
                            int g1 = group[i][j];
                            int g2 = group[x][y];
                            if (bridge[g1][g2] == 0 || bridge[g1][g2] > len)
                            {
                                bridge[g1][g2] = len;
                                bridge[g2][g1] = len;
                            }
                        }
                        break;
                    }
                    x += dx[k];
                    y += dy[k];
                    len += 1;
                }
            }
        }
    }
    for (int i = 1; i <= groups; i++) 
    {
        for (int j = i + 1; j <= groups; j++) 
        {
            if (bridge[i][j] > 0) 
            {
                edges.push_back(Edge({ i, j, bridge[i][j] }));
            }
        }
    }
    go(0, 0);
    cout << ans;
    return 0;
}
