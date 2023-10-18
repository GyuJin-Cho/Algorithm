#define _CRT_SECURE_NO_WARNINGS 
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
int arr[101][101];
int d[101][101];
deque<pair<int, int>>dq;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;
void BFS()
{
	while(!dq.empty())
	{
		pair<int, int> p = dq.front();
		dq.pop_front();
		for(int i=0;i<4;i++)
		{
			int ny = p.first+dy[i];
			int nx = p.second+dx[i];
			if(nx>-1&&ny>-1&&ny<n&&nx<m)
			{
				if(d[ny][nx]==-1)
				{
					if(arr[ny][nx]==0)
					{
						d[ny][nx] = d[p.first][p.second];
						dq.push_front(make_pair(ny, nx));
					}
					else
					{
						d[ny][nx] = d[p.first][p.second] + 1;
						dq.push_back(make_pair(ny, nx));
					}
				}
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%1d", &arr[i][j]);
			d[i][j] = -1;
		}
	dq.push_back(make_pair(0, 0));
	d[0][0] = 0;
	BFS();
	cout << d[n - 1][m - 1];

	return 0;
}