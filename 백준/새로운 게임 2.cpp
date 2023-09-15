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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int opposite(int dir)
{
    if (dir == 0) return 1;
    if (dir == 1) return 0;
    if (dir == 2) return 3;
    return 2;
}
void go(vector<vector<vector<pair<int, int>>>>& a, vector<tuple<int, int,int>>& where, int x, int y, int nx, int ny,int start)
{
    for(int i=start;i<a[x][y].size();i++)
    {
        auto& p = a[x][y][i];
        a[nx][ny].push_back(p);
        where[p.first] = make_tuple(nx, ny, (int)a[nx][ny].size() - 1);
    }
    a[x][y].resize(start);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> board[i][j];
        }
    }
    vector<vector<vector<pair<int, int>>>> a(n, vector<vector<pair<int, int>>>(n));
    vector<tuple<int, int, int>> where(m);
    for (int i = 0; i < m; i++) 
    {
        int x, y, dir;
        cin >> x >> y >> dir;
        a[x - 1][y - 1].push_back(make_pair(i, dir - 1));
        where[i] = make_tuple(x - 1, y - 1, (int)a[x - 1][y - 1].size() - 1);
    }
    for (int turn = 1; turn <= 1000; turn++) 
    {
        for (int k = 0; k < m; k++)
        {
            int x, y, index;
            tie(x, y, index) = where[k];
            int dir = a[x][y][index].second;
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (board[nx][ny] == 2) 
                {
                    a[x][y][index].second = opposite(dir);
                }
            }
            else
            {
                a[x][y][index].second = opposite(dir);
            }
            dir = a[x][y][index].second;
            nx = x + dx[dir];
            ny = y + dy[dir];
            if (0 <= nx && nx < n && 0 <= ny && ny < n)
            {
                if (board[nx][ny] == 0) {
                    go(a, where, x, y, nx, ny, index);
                }
                else if (board[nx][ny] == 1) 
                {
                    reverse(a[x][y].begin() + index, a[x][y].end());
                    go(a, where, x, y, nx, ny, index);
                }
                if (a[nx][ny].size() >= 4) 
                {
                    cout << turn << '\n';
                    return 0;
                }
            }
            else 
            {

            }
        }
    }
    cout << -1 << '\n';
    return 0;
}