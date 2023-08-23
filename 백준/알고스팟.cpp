#define _CRT_SECURE_NO_WARNINGS 
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

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int a[101][101];
int d[101][101];
deque<pair<int, int>> dq;
int n, m;

void BFS()
{
	while (!dq.empty())
	{
		int y = dq.front().first;
		int x = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
			{
				if (d[ny][nx] == -1)
				{
					if (a[ny][nx] == 0)
					{
						d[ny][nx] = d[y][x];
						dq.push_front({ ny,nx });
					}
					else
					{
						d[ny][nx] = d[y][x] + 1;
						dq.push_back({ ny,nx });
					}
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &a[i][j]);
			d[i][j] = -1;
		}
	}
	dq.push_back({0,0});
	d[0][0] = 0;
	BFS();
	cout << d[m - 1][n - 1];
	return 0;
}