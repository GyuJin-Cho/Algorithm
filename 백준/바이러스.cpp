#include<iostream>
#include<algorithm>

using namespace std;
int computer[101][101];
int k;
int n;
int cnt = 0;
bool visit[101];
void DFS(int v)
{
	visit[v] = true;
	for (int i = 1; i <= n; i++)
	{
		if (visit[i] || computer[v][i] == 0)
		{
			continue;
		}
		cnt++;
		DFS(i);
	}
}

int main()
{
	
	cin >> n;
	
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int u, v;
		cin >> u >> v;
		computer[u][v] = computer[v][u] = 1;
	}

	DFS(1);
	cout << cnt;
	return 0;
}