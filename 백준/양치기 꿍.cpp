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

using namespace std;

char arr[251][251];
bool visit[251][251];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int N, M;
int S;
int W;
void DFS(int y, int x)
{
    visit[y][x] = true;
    for(int i=0;i<4;i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0&&nx>=0&&ny<N&&nx<M)
        {
            if(!visit[ny][nx]&&arr[ny][nx]!='#')
            {
                if (arr[ny][nx] == 'v')
                {
                    W++;
                    DFS(ny, nx);
                }
                else if(arr[ny][nx] == 'k')
                {
                    S++;
                    DFS(ny, nx);
                }
                else
                {
                    DFS(ny, nx);
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int TotalS = 0, TotalW = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'k')
                TotalS++;
            else if (arr[i][j] == 'v')
                TotalW++;
        }
            

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(arr[i][j]=='#'||visit[i][j])
                continue;
            S = 0;
            W = 0;
            if (arr[i][j] == 'v')
                W++;
            else if (arr[i][j] == 'k')
                S++;
            DFS(i, j);
            if(S<=W)
            {
                TotalS -= S;
            }
            else if(S>W)
            {
                TotalW -= W;
            }
        }
    }
    cout << TotalS << ' ' << TotalW;
    return 0;
}
