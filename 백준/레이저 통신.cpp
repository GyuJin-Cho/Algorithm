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

using namespace std;
int n, m;
bool visit[101][101];
int d[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
class node
{
public:
	int y;
	int x;
	node(int y, int x) : y(y), x(x){}
	node()
	{
		y = 0;
		x = 0;
	}
};
void BFS(const vector<string> &a, vector<vector<int>> &d, const int& sx, const int& sy, const int& ex, const int& ey)
{
	queue<node> q;
	q.push(node(sy, sx));
	d[sy][sx] = 0;
	while(!q.empty())
	{
		node no = q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int nx = no.x + dx[i];
			int ny = no.y + dy[i];
			while(nx>=0&&nx<n&&ny>=0&&ny<m)
			{
				if (a[ny][nx] == '*')
					break;
				if(d[ny][nx]==-1)
				{
					d[ny][nx] = d[no.y][no.x] + 1;
					q.push(node(ny, nx));
				}
				ny += dy[i];
				nx += dx[i];
			}
		}
	}
	cout << d[ey][ex]-1;
}

int main()
{
	cin >> n >> m;
	vector<string> a(m);
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	for(int i=0;i<m;i++)
	{
		cin >> a[i];
		for(int j=0;j<n;j++)
		{
			if(a[i][j]=='C')
			{
				if(sx==-1)
				{
					sy = i;
					sx = j;
				}
				else
				{
					ey = i;
					ex = j;
				}
			}
		}
	}
	vector<vector<int>>d(m, vector<int>(n, - 1));
	BFS(a, d, sx, sy, ex, ey);
	return 0;
}