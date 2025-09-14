#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool Visited[1001] = { false, };
int N, M, V;
int map[1001][1001];
void InitVisit()
{
	for (bool& i : Visited)
		i = false;
}

void DFS(int V)
{
	cout << V << ' ';
	Visited[V] = true;
	for (int i = 1; i <= N; i++)
	{
		if (Visited[i] || map[V][i] == 0)
			continue;
		DFS(i);
	}
}

void BFS(int V)
{
	queue<int> q;
	q.push(V);
	Visited[V] = true;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		cout << v << ' ';
		for (int i = 1; i <= N; i++)
		{
			if (Visited[i] || map[v][i] == 0)
				continue;
			q.push(i);
			Visited[i] = true;
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

	InitVisit();

	DFS(V);
	cout << "\n";
	InitVisit();
	BFS(V);

	return 0;
}