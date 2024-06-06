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
vector<int> arr[10001];
bool visit[10001];
int n, m, v;

void DFS(int v)
{
	visit[v] = true;
	cout << v << ' ';
	for (int i = 0; i < arr[v].size(); i++)
	{
		if(!visit[arr[v][i]])
			DFS(arr[v][i]);
	}
}

void BFS(int v)
{
	visit[v] = true;
	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int n = q.front();
		cout << n << ' ';
		q.pop();
		for (int i = 0; i < arr[n].size(); i++)
		{
			if (!visit[arr[n][i]])
			{
				q.push(arr[n][i]);
				visit[arr[n][i]] = true;
			}
		}
	}
}

int main()
{
	cin >> n >> m >> v;
	int x, y;
	for(int i=0;i<m;i++)
	{
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for(int i=0;i<10001;i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}
	DFS(v);
	memset(visit, false, sizeof(visit));
	cout << '\n';
	BFS(v);
	return 0;
}