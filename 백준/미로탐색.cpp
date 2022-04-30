#include<iostream>
#include<queue>

using namespace std;

int map[101][101];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[101][101] = { false, };
#pragma warning(disable : 4996)
struct node
{
	int y;
	int x;
	int answer;
};

void BFS(int Y,int X)
{
	int ans = 0;

	queue<node> q;

	q.push({ 0,0,1 });
	visit[0][0] = true;
	while (!q.empty())
	{
		int cy = q.front().y;
		int cx = q.front().x;
		ans = q.front().answer;
		q.pop();

		if (cx == X - 1 && cy == Y-1)
			break;

		for (int i = 0; i < 4; i++)
		{
			int y = cy + dy[i];
			int x = cx + dx[i];

			if (!visit[y][x] && y >= 0 && x >= 0 && y < Y && x < X)
			{
				if (map[y][x] == 1)
				{
					visit[y][x] = true;
					q.push({ y,x,ans + 1 });
				}
			}

		}

	}

	cout << ans;
}

int main()
{
	int y, x;
	cin >> y >> x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	BFS(y,x);

	return 0;
}