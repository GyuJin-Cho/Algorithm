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

using namespace std;
bool a[2001][2001];
vector<int> g[2001];
vector<pair<int, int>> edges;
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;
		edges.push_back({ from,to });
		edges.push_back({ to,from });
		a[from][to] = a[to][from] = true;
		g[from].push_back(to);
		g[to].push_back(from);
	}

	m *= 2;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int A = edges[i].first;
			int B = edges[i].second;

			int C = edges[j].first;
			int D = edges[j].second;
			if (A == B || A == C || A == D || B == C || B == D || C == D)
				continue;

			if (!a[B][C])
				continue;

			for (int E : g[D])
			{
				if (A == E || B == E || C == E || D == E)
				{
					continue;
				}
				cout << 1;
				return 0;
			}
		}
	}
	cout << 0;
	return 0;
}