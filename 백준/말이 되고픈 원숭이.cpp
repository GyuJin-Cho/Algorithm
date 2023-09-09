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

int k, n, m;
int dx[] = { 0,0,1,-1,-2,-1,1,2,2,1,-1,-2 };
int dy[] = { 1,-1,0,0,1,2,2,1,-1,-2,-2,-1 };
int cost[] = { 0,0,0,0,1,1,1,1,1,1,1,1 };
int v[200][200];
int d[200][200][31];
int answer = -1;
void BFS()
{
	memset(d, -1, sizeof(d));
	queue<tuple<int, int, int>>q;
	d[0][0][0] = 0;
	q.push(make_tuple(0, 0, 0));
	while(!q.empty())
	{
		int x, y, c;
		tie(x, y, c) = q.front();
		q.pop();
		for(int i=0;i<12;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nc = c + cost[i];
			if(nx>=0&&nx<n&&ny>=0&&ny<m)
			{
				if (v[nx][ny] == 1)
					continue;
				if(nc<=k)
				{
					if(d[nx][ny][nc]==-1)
					{
						d[nx][ny][nc] = d[x][y][c] + 1;
						q.push(make_tuple(nx, ny, nc));
					}
				}
			}
		}
	}
	for(int i =0;i<=k;i++)
	{
		if(d[n-1][m-1][i]==-1)
			continue;
		if(answer==-1||answer>d[n-1][m-1][i])
		{
			answer = d[n - 1][m - 1][i];
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> k;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	BFS();
	cout << answer;
	return 0;
}