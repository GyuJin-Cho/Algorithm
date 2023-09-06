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
vector<int> a[100000];
bool check[100000];
vector<int> DFSorder;

void DFS(int Depth)
{
	if (check[Depth])
		return;
	DFSorder.push_back(Depth);
	check[Depth] = true;
	for (int y : a[Depth])
		DFS(y);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	vector<int> b(n);
	vector<int> order(n);
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
		b[i]--;
		order[b[i]] = i;
	}

	for(int i=0;i<n;i++)
	{
		sort(a[i].begin(), a[i].end(), [&](const int& u, const int& v)->bool{return order[u] < order[v]; });
	}
	DFS(0);
	if (DFSorder == b)
		cout << 1;
	else
		cout << 0;
	return 0;
}