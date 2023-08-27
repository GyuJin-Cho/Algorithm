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
int a[21][21];
int dice[7];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y, l;
	cin >> n >> m >> x >> y >> l;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	while (l--)
	{
		int k;
		cin >> k;
		k -= 1;
		int nx, ny;
		nx = x + dx[k];
		ny = y + dy[k];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		{
			continue;
		}
		if (k == 0)
		{
			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (k == 1)
		{
			int tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (k == 2)
		{
			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}
		else
		{
			int tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
		}
		x = nx;
		y = ny;
		if (a[x][y] == 0)
		{
			a[x][y] = dice[6];
		}
		else
		{
			dice[6] = a[x][y];
			a[x][y] = 0;
		}
		cout << dice[1] << '\n';
	}

	return 0;
}