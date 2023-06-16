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

struct node
{
	int y;
	int x;
	int cnt;
};

int map[301][301];
bool visit[301][301];
int dy[] = { -2,-1,1,2,2,1,-1,-2 };
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };

void visitInit()
{
	for (int i = 0; i < 301; i++)
		for (int j = 0; j < 301; j++)
			visit[i][j] = false;
}

void BFS(const int & size, const int& sy,const int& sx,const int& gy,const int& gx)
{
	visitInit();
	queue<node> q;
	q.push({ sy,sx,0 });

	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		if(n.y==gy&&n.x==gx)
		{
			cout << n.cnt<<'\n';
			break;
		}
		for(int i=0;i<8;i++)
		{
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if(ny>=0&&nx>=0&&nx<size&&ny<size)
			{
				if(!visit[ny][nx])
				{
					q.push({ ny,nx,n.cnt+1 });
					visit[ny][nx] = true;
				}
			}
		}
	}
}

int main()
{
	int N,size,sy,sx,gy,gx;
	cin >> N;
	while(N--)
	{
		cin >> size;
		cin >> sy >> sx;
		cin >> gy >> gx;
		BFS(size, sy, sx, gy, gx);
	}

	return 0;
}