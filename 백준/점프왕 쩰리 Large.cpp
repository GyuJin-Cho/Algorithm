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
#include<string.h>

using namespace std;

class node
{
public:
    int y;
    int x;

    node(int y, int x) : y(y), x(x) {}
    node() : y(0), x(0) {}
};

int Map[65][65];
bool visited[65][65];
int N;
int dy[] = { 0,1 };
int dx[] = { 1,0 };
bool check = false;
void DFS(int y, int x)
{
    visited[y][x] = true;
    if (Map[y][x] == -1)
    {
        check = true;
        return;
    }
    for (int i = 0; i < 2; i++)
    {
        int ny = (dy[i] * Map[y][x]) + y;
        int nx = (dx[i] * Map[y][x]) + x;
        if (ny >= 0 && nx >= 0 && ny < N && nx < N)
        {
            if (!visited[ny][nx])
            {
                DFS(ny, nx);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> Map[i][j];

    DFS(0,0);
    if (check)
        cout << "HaruHaru";
    else
        cout << "Hing";
    return 0;
}

