#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> V[200001];
bool visit[200001];
int N, M, R;
int result[200001];
int Count = 0;
void DFS(int R)
{
	if (visit[R])
		return;

	visit[R] = true;
	Count++;
	result[R] = Count;
	for (int i = 0; i < V[R].size(); i++)
	{
		DFS(V[R][i]);
	}
}

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> R;
	for (int i = 0; i < M; i++)
	{
		int v, e;
		cin >> v >> e;
		V[v].push_back(e);
		V[e].push_back(v);
	}
	
	for (int i = 1; i <= N; i++)
	{
		sort(V[i].begin(), V[i].end());
	}

	DFS(R);

	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << '\n';
	}
	return 0;
}