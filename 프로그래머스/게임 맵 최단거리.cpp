#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int r, c;
int answer = 0;
bool visited[101][101];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
struct Node
{
    int y;
    int x;
    int cnt;
};
void BFS(const vector<vector<int>>& maps,int y, int x)
{
    visited[y][x] = true;
    queue<Node> q;
    q.push({ y,x,1 });
    while (!q.empty())
    {
        Node n = q.front();
        q.pop();
        if (n.y == r - 1 && n.x == c - 1)
        {
            answer = n.cnt;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int ny = n.y + dy[i];
            int nx = n.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= r || nx >= c)
                continue;
            if (visited[ny][nx])
                continue;
            if (maps[ny][nx] == 0)
                continue;
            q.push({ ny,nx,n.cnt + 1 });
            visited[ny][nx] = true;
        }
    }
    answer = -1;
}

int solution(vector<vector<int> > maps)
{
    
    r = maps.size();
    c = maps[0].size();
    BFS(maps,0, 0);

    return answer;
}

int main()
{
    vector<vector<int>> v = { {1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1} };
    cout << solution(v);

    return 0;
}