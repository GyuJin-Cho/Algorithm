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
vector<int> V[251];
int N, M;
bool visited[251];
void DFS(int Depth)
{
	visited[Depth] = true;

	for (int i = 0; i < V[Depth].size(); i++)
	{
		if (!visited[V[Depth][i]])
		{
			DFS(V[Depth][i]);
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		V[s].push_back(e);
		V[e].push_back(s);
	}
	DFS(1);
	bool ch = false;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			ch = true;
			cout << i << '\n';
		}
	}
	if (!ch)
		cout << 0 << '\n';
	return 0;
}