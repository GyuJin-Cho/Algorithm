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
int a[50][50];
int d[50][50];
int room[50 * 50];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0 };
int BFS(int x, int y, int rooms)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	d[x][y] = rooms;
	int cnt = 0;
	while(!q.empty())
	{
		tie(x, y) = q.front();
		q.pop();
		cnt += 1;
		for(int k=0;k<4;k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(nx>=0&&nx<n&&ny>=0&&ny<m)
			{
				if(d[nx][ny]!=0)
					continue;
				if(a[x][y]&(1<<k))
					continue;
				q.push({ nx,ny });
				d[nx][ny] = rooms;
			}
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	int rooms = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(d[i][j]==0)
			{
				rooms += 1;
				room[rooms] = BFS(i, j, rooms);
			}
		}
	}
	cout << rooms << '\n';
	int answer = 0;
	for(int i=1;i<=rooms;i++)
	{
		answer = max(answer, room[i]);
	}
	cout << answer << '\n';
	answer = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = i;
			int y = j;
			for(int k=0;k<4;k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				{
					if (d[nx][ny] == d[x][y])
						continue;
					if(a[x][y]&(1<<k))
					{
						answer = max(answer, room[d[x][y]] + room[d[nx][ny]]);
					}
				}
			}
		}
	}
	cout << answer;
	return 0;
}