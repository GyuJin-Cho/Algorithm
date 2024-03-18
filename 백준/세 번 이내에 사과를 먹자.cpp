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
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<vector<int>> board;
vector<vector<int>> cost;
bool ans;
struct node
{
	int cost;
	int depth;
};
void dfs(int y, int x, int d)
{
	if (d == 3)
	{
		if (cost[y][x] >= 2)
			ans = true;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5)
				continue;
			if (board[ny][nx] == -1)
				continue;

			if (board[ny][nx] == 1)
				cost[ny][nx] = max(cost[ny][nx], cost[y][x] + 1);
			else
				cost[ny][nx] = max(cost[ny][nx], cost[y][x]);
			board[y][x] = -1;
			dfs(ny, nx, d + 1);
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, x, y;

	for (int i = 0; i < 5; i++)
	{
		vector<int> v;
		vector<int> v2;
		for (int j = 0; j < 5; j++)
		{
			cin >> n;
			v.push_back(n);
			v2.push_back(0);
		}
		board.push_back(v);
		cost.push_back(v2);
	}
	cin >> y >> x;
	dfs(y, x, 0);
	cout << ans;
	return 0;
}