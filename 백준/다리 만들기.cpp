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
int arr[100][100];
int visited[100][100];
int n;
int answer = 217400000;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void DFS(int y,int x, int idx)
{
	arr[y][x] = idx;
	for(int i=0;i<4;i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		if(ny>=0&&nx>=0&&ny<n&&nx<n)
		{
			if(arr[ny][nx]==-1)
			{
				DFS(ny, nx, idx);
			}
		}
	}
}

void BFS(int idx)
{
	queue<pair<int, int>> q;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==idx)
			{
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}

	int ans = 0;

	while(!q.empty())
	{
		int size = q.size();
		for(int i=0;i<size;i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for(int i=0;i<4;i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if(ny>=0&&nx>=0&&ny<n&&nx<n)
				{
					if(arr[ny][nx]!=0&&arr[ny][nx]!=idx)
					{
						answer = min(answer, ans);
						return;
					}
					if(arr[ny][nx]==0&&!visited[ny][nx])
					{
						visited[ny][nx] = true;
						q.push({ ny,nx });
					}
				}
			}
		}
		ans++;
	}
}

int main()
{
	cin >> n;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				arr[i][j] = -1;
		}
	}
	int idx = 1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==-1)
			{
				DFS(i, j, idx);
				idx++;
			}
		}
	}

	for(int i=1;i<idx;i++)
	{
		memset(visited, false, sizeof(visited));
		BFS(i);
	}
	cout << answer;

	return 0;
}