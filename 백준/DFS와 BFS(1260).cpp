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

void DFS(int num)
{
	cout << num << ' ';
	visit[num] = true;
	for(int i=0;i<arr[num].size();i++)
	{
		if(!visit[arr[num][i]])
			DFS(arr[num][i]);
	}
}

void BFS(int num)
{
	visit[num] = true;
	queue<int> q;
	q.push(num);
	while(!q.empty())
	{
		int now = q.front();
		cout << now << ' ';
		q.pop();
		for(int i=0;i<arr[now].size();i++)
		{
			if(!visit[arr[now][i]])
			{
				q.push(arr[now][i]);
				visit[arr[now][i]] = true;
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