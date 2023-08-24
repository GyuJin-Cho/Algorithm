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
#include <cstring>
using namespace std;
int d[1001][1001];
queue<pair<int, int>>q;
int n;
void BFS()
{
	while (!q.empty())
	{
		int s, c;
		s = q.front().first;
		c = q.front().second;
		q.pop();
		if (d[s][s] == -1)
		{
			d[s][s] = d[s][c] + 1;
			q.push({ s,s });
		}
		if (s + c <= n && d[s + c][c] == -1)
		{
			d[s + c][c] = d[s][c] + 1;
			q.push({ s + c,c });
		}
		if (s - 1 >= 0 && d[s - 1][c] == -1)
		{
			d[s - 1][c] = d[s][c] + 1;
			q.push({ s - 1,c });
		}
	}
}
int main()
{
	cin >> n;
	memset(d, -1, sizeof(d));
	q.push(make_pair(1, 0));
	d[1][0] = 0;
	BFS();
	int ans = -1;
	for (int i = 0; i <= n; i++)
	{
		if (d[n][1] != -1)
		{
			if (ans == -1 || ans > d[n][i])
			{
				ans = d[n][i];
			}
		}
	}
	cout << ans;
	return 0;
}