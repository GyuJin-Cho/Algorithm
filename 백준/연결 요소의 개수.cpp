#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> V[1001];
bool visit[1001] = { false, };

void DFS(int N)
{

	visit[N] = true;

	for (int i = 0; i < V[N].size(); i++)
	{
		int n = V[N][i];
		if (!visit[n])
		{
			DFS(n);
		}
	}

}

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		V[s].push_back(e);
		V[e].push_back(s);
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			DFS(i);
			ans++;
		}
	}

	cout << ans;

	return 0;
}