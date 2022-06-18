#include<iostream>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

struct node
{
	int y;
	int x;
	int cnt;
};

char map[101][101];
bool visit[101][101] = { false, };

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int ourTeamCount = 0;
int EnemyTeamCount = 0;
int n, m;
void BFS(int y, int x, bool CheckEnemy)
{
	queue<node> q;
	q.push({ y, x , 1});
	visit[y][x] = true;
	int cnt = 0;
	int Count = 1;
	if (CheckEnemy)
	{
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			cnt = q.front().cnt;

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m)
				{
					if (!visit[ny][nx] && map[ny][nx] == 'B')
					{
						visit[ny][nx] = true;
						q.push({ ny, nx, cnt + 1 });
						Count++;
					}
				}
			}
		}
		EnemyTeamCount += Count * Count;
	}
	else
	{
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			cnt = q.front().cnt;

			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m)
				{
					if (!visit[ny][nx] && map[ny][nx] == 'W')
					{
						visit[ny][nx] = true;
						q.push({ ny, nx, cnt + 1 });
						Count++;
					}
				}
			}
		}
		ourTeamCount += Count*Count;
	}
	
}

int main()
{
	
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visit[i][j])
			{
				if (map[i][j] == 'W')
				{
					BFS(i, j, false);
				}
				else
				{
					BFS(i, j, true);
				}
			}
		}
	}
	cout << ourTeamCount << " " << EnemyTeamCount;
	return 0;
}