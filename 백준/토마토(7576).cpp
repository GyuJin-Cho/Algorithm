#include<iostream>
#include<queue>

using namespace std;

int M, N;
bool Visited[1001][1001] = { false, };
int Tomato[1001][1001] = { 0, };
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int ch[1001][1001];
queue<pair<int, int>> q;
void BFS()
{
	while (!q.empty())
	{
		pair<int, int> Now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = Now.first + dy[i];
			int nx = Now.second + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (Tomato[ny][nx] != -1 && !Visited[ny][nx])
				{
					Tomato[ny][nx] = 1;
					ch[ny][nx] = ch[Now.first][Now.second] + 1;
					Visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			cin >> Tomato[y][x];
			if (Tomato[y][x] == 1)
			{
				ch[y][x] = 0;
				Visited[y][x] = true;
				q.push({ y,x });
			}
		}
	}

	BFS();

	int ans = -217400000;
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < M; ++x)
		{
			if (Tomato[y][x] == 0)
			{
				cout << -1;
				return 0;
			}
			ans = max(ch[y][x], ans);
		}
	}

	cout << ans;

	return 0;
}