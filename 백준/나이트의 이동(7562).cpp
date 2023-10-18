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
const int MAX = 301;
class node
{
public:
	int y;
	int x;
	int cnt;
	node(int y, int x, int cnt) : y(y),x(x),cnt(cnt){}
	node() : y(0), x(0), cnt(0){}
};
bool visit[MAX][MAX];
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { -2,-1,1,2,2,1,-1,-2 };

void BFS(const int& n,int sy, int sx, int ey, int ex)
{
	memset(visit, false, sizeof(visit));
	queue<node> q;
	q.push(node(sy, sx, 0));
	visit[sy][sx] = true;
	while(!q.empty())
	{
		node N = q.front();
		q.pop();
		if(N.y==ey&&N.x==ex)
		{
			cout << N.cnt<<'\n';
			return;
		}
		for(int i=0;i<8;i++)
		{
			int nx = dx[i] + N.x;
			int ny = dy[i] + N.y;
			if(nx<n&&ny<n&&nx>-1&&ny>-1)
			{
				if(!visit[ny][nx])
				{
					visit[ny][nx] = true;
					q.push(node(ny, nx, N.cnt + 1));
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int sy, sx;
		cin >> sy >> sx;
		int ey, ex;
		cin >> ey >> ex;
		BFS(n, sy, sx, ey, ex);
	}

	return 0;
}