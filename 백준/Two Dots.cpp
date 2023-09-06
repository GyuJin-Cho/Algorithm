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
#include<string>

using namespace std;
char a[55][55];
bool check[55][55];
int dist[55][55];
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool go(int y, int x, int cnt, char color)
{
	if(check[y][x])
	{
		if (cnt - dist[y][x] >= 4)
		{
			return true;
		}
		else
			return false;
	}
	check[y][x] = true;
	dist[y][x] = cnt;
	for(int k=0;k<4;k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(0<=nx&&nx<m&&0<=ny&&ny<n)
		{
			if(a[ny][nx] == color)
			{
				if (go(ny, nx, cnt + 1, color))
					return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j])
				continue;
			memset(dist, 0, sizeof(dist));
			bool ch = go(i, j, 1, a[i][j]);
			if(ch)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";


	return 0;
}