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
int N, M, S, E;
vector<int> V[300001];
bool visited[300001];
struct node
{
	int pos;
	int cnt;
};

void BFS()
{
	queue<node> q;
	visited[S] = true;
	q.push({ S,0 });
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		if (n.pos == E)
		{
			cout << n.cnt;
			return;
		}
		if (n.pos + 1 <= N )
		{
			if (!visited[n.pos + 1])
			{
				q.push({ n.pos + 1,n.cnt + 1 });
				visited[n.pos + 1] = true;
			}
		}
		if (n.pos - 1 > 0 )
		{
			if (!visited[n.pos - 1])
			{
				q.push({ n.pos - 1,n.cnt + 1 });
				visited[n.pos - 1] = true;
			}	
		}
		for (int i = 0; i < V[n.pos].size(); i++)
		{
			int npos = V[n.pos][i];
			if (npos <= N && npos > 0)
			{
				if (!visited[npos])
				{
					q.push({ npos,n.cnt + 1 });
					visited[npos] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

	BFS();

	return 0;
}