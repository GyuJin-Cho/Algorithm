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
char arr[1002][1002];
bool visited[1002][1002];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int r, c, sx, sy, fx, fy;

struct node
{
	int y;
	int x;
	int cnt;
};
queue<pair<int, int>> fq;

void FireMove()
{

	vector<pair<int, int>> v;
	while (!fq.empty())
	{
		int y, x;
		y = fq.front().first;
		x = fq.front().second;
		fq.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny<c + 1 && nx<r + 1 && ny>0 && nx>0 && arr[ny][nx] == '.')
			{
				v.push_back({ ny,nx });
				arr[ny][nx] = '*';
			}
		}
	}
	for (auto& i : v)
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
	while (!jq.empty())
	{
		node n = jq.front();
		jq.pop();
		if (n.cnt != ch)
		{
			FireMove();
			ch++;
		}
		if (n.y > c || n.x > r || n.y <= 0 || n.x <= 0)
		{
			cout << n.cnt<<'\n';
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = dy[i] + n.y;
			int nx = dx[i] + n.x;
			if (ny <= c + 1 && nx <= r + 1 && ny >= 0 && nx >= 0)
			{
				if (!visited[ny][nx] && arr[ny][nx] == '.' && arr[ny][nx] != '*' && arr[n.y][n.x] != '*')
				{
					jq.push({ ny,nx,n.cnt + 1 });
					visited[ny][nx] = true;
				}
			}
		}


	}

	cout << "IMPOSSIBLE"<<'\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	
	while(n--)
	{
		memset(arr, '.', sizeof(arr));
		memset(visited, false, sizeof(visited));
		cin >> r >> c;
		for (int i = 1; i <= c; i++)
		{
			for (int j = 1; j <= r; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					sy = i;
					sx = j;
					arr[i][j] = '.';
				}
				else if (arr[i][j] == '*')
				{
					fy = i;
					fx = j;
					fq.push({ fy,fx });
				}
			}
		}
		BFS();
		while (!fq.empty())
			fq.pop();
	}
	


	return 0;
}