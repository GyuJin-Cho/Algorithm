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
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int arr[1001][1001];
bool visit[1001][1001];
int ch[1001][1001];
queue<pair<int, int>> q;
void BFS()
{
	while(!q.empty())
	{
		pair<int,int> now = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int ny = dy[i] + now.first;
			int nx = dx[i] + now.second;
			if(ny<m&&nx<n&&ny>=0&&nx>=0)
			{
				if(!visit[ny][nx]&&arr[ny][nx]>=0)
				{
					arr[ny][nx] = 1;
					ch[ny][nx] = ch[now.first][now.second] + 1;
					q.push({ ny,nx });
					visit[ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				ch[i][j] = 0;
				q.push({ i,j });
				visit[i][j] = true;
			}
				
		}
	BFS();

	int ans = -2174000;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j]==0)
			{
				cout << -1;
				return 0;
			}
			ans = max(ans, ch[i][j]);
		}
	cout << ans;
}