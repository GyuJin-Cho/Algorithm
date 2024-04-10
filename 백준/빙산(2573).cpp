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
int Map[301][301];
bool visit[301][301];
bool YearCheck[301][301];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int N, M;
void VisitInit()
{
	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++)
			visit[i][j] = false;

	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++)
			YearCheck[i][j] = false;
}

void DFS(int y, int x)
{
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny >= 0 && nx >= 0 && ny < N && nx < M)
		{
			if (!visit[ny][nx] && Map[ny][nx] > 0)
			{
				DFS(ny, nx);
			}
		}
	}
}

void Search()
{
	int Year = 0;
	while (1)
	{
		int cnt = 0;
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] > 0 && !visit[i][j])
				{
					flag = true;
					DFS(i, j);
					cnt++;
				}
			}
		}
		if (!flag)
		{
			cout << 0;
			break;
		}
		if (cnt >= 2)
		{
			cout << Year;
			break;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Map[i][j] > 0)
				{
					for (int z = 0; z < 4; z++)
					{
						int ny = dy[z] + i;
						int nx = dx[z] + j;
						if (ny >= 0 && nx >= 0 && ny < N && nx < M)
						{
							if (Map[ny][nx] == 0)
							{
								if (Map[i][j] - 1 >= 0 && !YearCheck[ny][nx])
								{
									Map[i][j]--;
									if (Map[i][j] == 0)
									{
										YearCheck[i][j] = true;
									}
								}
								else if (Map[i][j] == 0)
								{
									break;
								}
							}
						}
					}
				}
			}
		}

		Year++;
		VisitInit();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Map[i][j];
	Search();



	return 0;
}