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

int n, u, v, cost;
int Node, Ans;
bool Visit[100001];
vector<pair<int, int>> Graph[100001];

void DFS(int x, int dist)
{
	Visit[x] = true;

	if (dist > Ans)
	{
		Ans = dist;
		Node = x;
	}

	for (int i = 0; i < Graph[x].size(); i++)
	{
		int next_Node = Graph[x][i].first;
		int next_dist = Graph[x][i].second + dist;
		if (!Visit[next_Node])
		{
			Visit[next_Node] = true;
			DFS(next_Node, next_dist);
			Visit[next_Node] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i < n; i++)
	{
		cin >> u >> v >> cost;
		Graph[u].push_back({ v,cost });
		Graph[v].push_back({ u,cost });
	}

	DFS(1, 0);
	Ans = 0;
	memset(Visit, false, sizeof(Visit));
	DFS(Node, 0);
	cout << Ans;
	return 0;
}