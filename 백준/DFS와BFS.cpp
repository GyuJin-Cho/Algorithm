#include<iostream>
#include<vector>
#include<stack>
#include<queue>

int map[1001][1001];
int N, M, V;
bool visit[1001];
using namespace std;

void Initbool()
{
	for (int i = 0; i < 1001; i++)
	{
		visit[i] = false;
	}
}

void dfs(int v)
{
	cout << v << ' ';
	visit[v] = true;
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] || map[v][i] == 0)
		{
			continue;
		}
		dfs(i);
	}
}

void bfs(int v)
{
	Initbool();
	queue<int> q;
	q.push(v);
	visit[v] = true;

	while (!q.empty())
	{
		v = q.front();
		cout << q.front() << ' ';
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] || map[v][i]==0)
				continue;
			q.push(i);
			visit[i] = true;
		}
	}

}

int main()
{
	
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}
	Initbool();
	dfs(V);
	cout << endl;
	bfs(V);
	return 0;
}