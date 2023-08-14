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
const int MAX = 10;
int n, m, k;
int a[MAX + 1][MAX + 1];
bool c[MAX + 1][MAX + 1];

int ans = -217400000;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
void DFS(int cnt, int sum)
{
	if (cnt == k)
	{
		ans = max(ans, sum);
		return;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (c[y][x])
				continue;
			bool ch = true;
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx >= 0 && ny >= 0 && nx < m && ny < n)
				{
					if (c[ny][nx])
						ch = false;
				}
			}
			
			if (ch)
			{
				c[y][x] = true;
				DFS(cnt + 1, sum + a[y][x]);
				c[y][x] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	DFS(0, 0);
	cout << ans << '\n';
	return 0;
}