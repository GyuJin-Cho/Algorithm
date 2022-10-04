#include<iostream>
#include<queue>
#include<vector>
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
	vector<int> v;
	q.push({ N,0 });
	visit[N] = true;
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		if (n.Position == K)
		{
			int d=n.Position;
			path.push_back(d);
			while (d!=N)
			{
				path.push_back(Direction[d]);
				d = Direction[d];
			}
			return n.ans;
		}

		if (2 * n.Position < 100001)
		{
			if (!visit[2 * n.Position])
			{
				q.push({2 * n.Position,n.ans + 1 });
				Direction[2*n.Position] = n.Position;
				visit[2 * n.Position] = true;
			}
		}
		if (n.Position - 1 >= 0)
		{
			if (!visit[n.Position - 1])
			{
				q.push({ n.Position - 1,n.ans + 1 });
				Direction[n.Position - 1] = n.Position;
				visit[n.Position - 1] = true;
			}
		}
		if (n.Position + 1 < 100001)
		{
			if (!visit[n.Position + 1])
			{
				q.push({ n.Position + 1,n.ans + 1 });
				Direction[n.Position+1] = n.Position;
				visit[n.Position + 1] = true;
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