#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;
vector<string>a;
int n;
int answer;
int color[51][51];
int dx[] = { 0,1,-1,1,-1,0 };
int dy[] = { -1,-1,0,0,1,1 };

void DFS(int y, int x, int c)
{
	color[y][x] = c;
	answer = max(answer, 1);
	for(int k=0;k<6;k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		if(0<=nx&&nx<n&&0<=ny&&ny<n)
		{
			if(a[ny][nx] == 'X')
			{
				if(color[ny][nx]==-1)
				{
					DFS(ny, nx, 1 - c);
				}
			}
			answer = max(answer, 2);
			if(color[ny][nx]==c)
			{
				answer = max(answer, 3);
			}
		}
	}
}

int main()
{
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(color, -1, sizeof(color));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if (a[i][j] == 'X' && color[i][j] == -1)
				DFS(i, j, 0);
		}
	}
	cout << answer;
	return 0;
}