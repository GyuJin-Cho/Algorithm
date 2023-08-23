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
vector<int> a[20001];
int color[20001];

bool DFS(int node , int c)
{
	color[node] = c;
	for (int i = 0; i < a[node].size(); i++)
	{
		int next = a[node][i];
		if (color[next] == 0)
		{
			if (!DFS(next, 3 - c))
				return false;
		}
		else if (color[next] == color[node])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		bool ch = true;
		for (int i = 1; i <= n; i++)
		{
			if (color[i] == 0)
			{
				if (!DFS(i, 1))
				{
					ch = false;
				}
			}
		}
		cout << (ch ? "YES" : "NO")<<'\n';
	}


	return 0;
}