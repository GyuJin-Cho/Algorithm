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
vector<int> a[100001];
int parent[100001];
int order[100001];
bool check[100001];
int n;


bool BFS()
{
	queue<int> q;
	q.push(0);
	check[0] = true;
	int m = 1;
	for(int i=0;i<n;i++)
	{
		if (q.empty())
			return false;
		int x = q.front();
		q.pop();
		if (x != order[i])
			return false;
		int cnt = 0;
		for(int y : a[x])
		{
			if(!check[y])
			{
				parent[y] = x;
				cnt += 1;
			}
		}
		for(int j=0;j<cnt;j++)
		{
			if (m + j >= n || parent[order[m + j]] != x)
				return false;
			q.push(order[m + j]);
			check[order[m + j]] = true;
		}
		m += cnt;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n-1;i++)
	{
		int u, v;
		cin >> u >> v;
		u -= 1;
		v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=0;i<n;i++)
	{
		cin >> order[i];
		order[i] -= 1;
	}

	if (BFS())
		cout << 1;
	else
		cout << 0;

	return 0;
}