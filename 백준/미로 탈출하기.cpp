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
int n, m;
char s[501][501];
int d[501][501];
int DFS(int y, int x)
{
	if (x < 0 || y < 0 || y >= n || x >= m)
		return 1;
	if (d[y][x] != -1)
		return d[y][x];
	d[y][x] = 0;
	if (s[y][x] == 'R')
		d[y][x] = DFS(y, x + 1);
	else if (s[y][x] == 'D')
		d[y][x] = DFS(y + 1, x);
	else if (s[y][x] == 'L')
		d[y][x] = DFS(y, x - 1);
	else
		d[y][x] = DFS(y - 1, x);
	return d[y][x];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		for (int j = 0; j < m; j++)
			d[i][j] = -1;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] == -1)
				DFS(i, j);
	int answer = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] == 1)
				answer++;
	cout << answer;
	return 0;
}