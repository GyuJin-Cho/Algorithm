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
#pragma warning(disable:4996)
using namespace std;

struct node
{
	int Position;
	int ans;
};

int dx[] = { 1,-1 };
bool visit[100001] = { false, };
int Direction[100001] = { 0, };
vector<int> path;
int BFS(const int& N, const int& K)
{
	queue<node> q;
	q.push({ N,0 });
	visit[N] = true;
	while(!q.empty())
	{
		node n = q.front();
		q.pop();

		if(n.Position==K)
		{
			int d = n.Position;
			path.push_back(d);
;			while(d!=N)
			{
				path.push_back(Direction[d]);
				d = Direction[d];
			}
			return n.ans;
		}

		for(int i=0;i<3;i++)
		{
			if(i==2)
			{
				int nx = n.Position * 2;
				if(nx < 100001&&!visit[nx])
				{
					q.push({ nx,n.ans + 1 });
					Direction[nx] = n.Position;
					visit[nx] = true;
				}
				continue;
			}
			int nx = n.Position + dx[i];
			if(nx >= 0&&nx < 100001)
			{
				if(!visit[nx])
				{
					q.push({ nx,n.ans + 1 });
					Direction[nx] = n.Position;
					visit[nx] = true;
				}
			}
		}
	}
}

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);

	printf("%d\n", BFS(N, K));
	for (int i = path.size()-1; i >=1; i--)
	{
		printf("%d ", path[i]);
	}
	printf("%d", path[0]);
	return 0;
}