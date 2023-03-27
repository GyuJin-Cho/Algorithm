#include<iostream>

using namespace std;
int N, M;
int Max = -2147000000;

int map[501][501];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[501][501];
int Sum = 0;
void DFS(int y, int x, int sum)
{
	Sum = sum;
	visit[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if(ny>0&&nx>0&&ny<=N&&nx<=M)
		{
			if(!visit[ny][nx]&&map[ny][nx]==1)
			{
				DFS(ny, nx, Sum + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin >> map[i][j];
		}
	}

	int count = 0;

	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(map[i][j]==1&&!visit[i][j])
			{
				DFS(i, j,1);
				count++;
				Max = max(Max, Sum);
			}
		}
	}
	if(Max == -2147000000)
	{
		cout << count << '\n' << 0;

	}
	else
	{
		cout << count << '\n' << Max;

	}
	return 0;
}