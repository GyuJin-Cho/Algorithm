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
vector<tuple<int, int, int>>V;
bool check;
long long ans;
int parent[10001];

int FindParent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = FindParent(parent[x]);
}

void UnionNode(int u, int v)
{
	check = false;
	u = FindParent(u);
	v = FindParent(v);
	if (u == v)
		return;
	else
	{
		parent[u] = v;
		check = true;
	}
}

int main()
{
	int v, e;
	cin >> v >> e;
	int x, y;
	int d;
	for (int i = 1; i <= v; i++)
		parent[i] = i;

	for (int i = 0; i < e; i++)
	{
		cin >> x >> y >> d;
		V.push_back({ d,x,y });
	}
	sort(std::begin(V), std::end(V));
	for(int i=0;i<e;i++)
	{
		UnionNode(get<1>(V[i]), get<2>(V[i]));
		if (check)
			ans += get<0>(V[i]);
	}
	cout << ans;
	return 0;
}