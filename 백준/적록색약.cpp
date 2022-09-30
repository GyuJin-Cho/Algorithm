#include<iostream>
#include <queue>
#include <memory>
using namespace std;

char map[101][101] = { "",};
bool visit[101][101] = { false, };
int R, G, B;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct node
{
	int y;
	int x;
};

void InitViist()
{
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			visit[i][j] = false;
		}
	}
}

void BFS(char Color, int Y, int X, int N)
{
	switch (Color)
	{
		case 'R':
		{
			R++;
			break;
		}
		case 'G' :
		{
			G++;
			break;
		}
		case 'B' :
		{
			B++;
			break;
		}
	}
	queue<node> q;
	q.push({ Y,X });
	visit[Y][X] = true;
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = n.y+dy[i];
			int nx = n.x+dx[i];

			if (ny >= 0 && nx >= 0 && ny < N && nx < N)
			{
				if (!visit[ny][nx]&&map[ny][nx]==Color)
				{
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (map[i][j])
			{
				case 'R':
				{
					if (!visit[i][j])
					{
						BFS('R', i, j, N);
					}
					break;
				}
				case 'G' :
				{
					if (!visit[i][j])
					{
						BFS('G', i, j, N);
					}
					break;
				}
				case 'B':
				{
					if (!visit[i][j])
					{
						BFS('B', i, j, N);
					}
					break;
				}

			}
		}
	}
	int Normal = R + G + B;
	R = G = B = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'R')
			{
				map[i][j] = 'G';
			}
		}
	}
	
	InitViist();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			switch (map[i][j])
			{
				case 'G':
				{
					if (!visit[i][j])
					{
						BFS('G', i, j, N);
					}
					break;
				}
				case 'B':
				{
					if (!visit[i][j])
					{
						BFS('B', i, j, N);
					}
					break;
				}

			}
		}
	}
	int ColorWeakness = G + B;

	cout << Normal << " " << ColorWeakness;
	return 0;
}