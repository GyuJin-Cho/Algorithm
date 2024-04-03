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
constexpr int MAX = 10001;
constexpr int INF = 1e9;
int n, d;
vector<pair<int,int>> V[MAX];
vector<int> m(10001, INF);
int from, to, cost;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> d;
	for (int i = 0; i < n; ++i)
	{
		int u, v, c;
		cin >> u >> v >> c;
		if (v > d || v - u < c)
			continue;
		V[v].push_back({ u,c });
	}

	m[0] = 0;

	for (int i = 1; i <= d; i++)
	{
		m[i] = m[i - 1] + 1;
		for (int j = 0; j < V[i].size(); ++j)
		{
			m[i] = min(m[i], m[V[i][j].first] + V[i][j].second);
		}
	}
	cout << m[d];

	return 0;
}