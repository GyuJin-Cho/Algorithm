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
int N, M;
int arr[7][7];
int ans = 1e9;

int dx[] = { -1,0,1 };

int DFS(int y, int x, int d)
{
	if (y == N)
		return 0;

	int res = 1e9;
	for (int i = 0; i < 3; i++)
	{
		if (d == i)
			continue;

		if (x + dx[i] >= 0 && x + dx[i] < M)
		{
			res = min(res, DFS(y + 1, x + dx[i], i) + arr[y][x]);
		}
	}
	return res;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for (int i = 0; i < M; i++)
		ans = min(ans, DFS(0, i, -1));
	cout << ans;
	return 0;
}