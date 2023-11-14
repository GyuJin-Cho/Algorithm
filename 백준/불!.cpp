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
char arr[1002][1002] ;
bool visited[1002][1002];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int r, c,sx, sy, fx, fy;

struct node
{
	int y;
	int x;
	int cnt;
};
static queue<pair<int, int>> fq;

void FireMove()
{
	
	vector<pair<int, int>> v;
	while(!fq.empty())
	{
		int y, x;
		y = fq.front().first;
		x = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if(ny<r+1&&nx<c+1&&ny>-1&&nx>-1&&arr[ny][nx]=='.')
			{
				v.push_back({ ny,nx });
				arr[ny][nx] = 'F';
			}
		}
	}
	for(auto & i : v)
	{
		fq.push(i);
	}
}

void BFS()
{
	queue<node> jq;
	jq.push({ sy,sx,0 });
	visited[sy][sx] = true;
	int ch = 0;
	while(!jq.empty())
	{
		node n = jq.front();
		jq.pop();
		if (n.cnt != ch)
		{
			FireMove();
			ch++;
		}
		if(n.y>r||n.x>c||n.y<=0||n.x<=0)
		{
			cout << n.cnt;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int ny = dy[i] + n.y;
			int nx = dx[i] + n.x;
			if(ny<=r+1&&nx<=c+1&&ny>=0&&nx>=0)
			{
				if (!visited[ny][nx]&&arr[ny][nx]=='.'&&arr[ny][nx]!='F'&&arr[n.y][n.x]!='F')
				{
					jq.push({ ny,nx,n.cnt + 1 });
					visited[ny][nx] = true;
				}
			}
		}
		
			
	}

	cout << "IMPOSSIBLE";
}

int main()
{
	cin >> r >> c;
	memset(arr, '.', sizeof(arr));
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'J')
			{
				sy = i;
				sx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'F')
			{
				fy = i;
				fx = j;
				fq.push({ fy,fx });
			}
		}
	}
	
	BFS();

	return 0;
}