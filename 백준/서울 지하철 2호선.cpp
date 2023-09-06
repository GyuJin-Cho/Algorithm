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
int n;
vector<int> a[3001];
int check[3001];
int dist[3001];

int DFS(int x, int p)
{
	if (check[x] == 1)
		return x;

	check[x] = 1;
	for(int y : a[x])
	{
		if(y==p)
			continue;
		int res = DFS(y, x);
		if (res == -2)
			return -2;
		if(res>=0)
		{
			check[x] = 2;
			if (x == res)
				return -2;
			else
				return res;
		}
	}
	return -1;
}

int main()
{
	cin >> n;
	for(int i = 0; i<n; i++)
	{
		int u, v;
		cin >> u >> v;
		u -= 1; v -= 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	DFS(0, -1);
	queue<int> q;
	for(int i=0;i<n;i++)
	{
		if(check[i]==2)
		{
			dist[i] = 0;
			q.push(i);
		}
		else
		{
			dist[i] = -1;
		}
	}
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		for(int y : a[x])
		{
			if(dist[y]==-1)
			{
				q.push(y);
				dist[y] = dist[x] + 1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << dist[i] << ' ';
	}
	return 0;
}