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
#include<string.h>
using namespace std;

struct node
{
	int y;
	int x;
};

int t, h, w, cnt = 0;
char arr[100][100];
bool visited[100][100];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void BFS(int y,int x)
{
	queue<node> q;
	q.push({ y,x });
	visited[y][x] = true;

	while(!q.empty())
	{
		node n = q.front();
		q.pop();

		for(int i=0;i<4;i++)
		{
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if(ny>=0&&nx>=0&&ny<h&&nx<w)
			{
				if(!visited[ny][nx]&&arr[ny][nx]=='#')
				{
					q.push({ ny,nx });
					visited[ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> t;
	while(t--)
	{
		cnt = 0;
		memset(visited, false, sizeof(visited));
		cin >> h >> w;
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				cin >> arr[i][j];
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if(arr[i][j]=='#'&&!visited[i][j])
				{
					BFS(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}