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
vector<int> arr[20001];
int visited[20001];
int n, m;

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 0;

	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for(auto& i : arr[cur])
		{
			if(visited[i]==0&&i!=1)
			{
				q.push(i);
				visited[i] = visited[cur] + 1;
			}
		}

	}
}

int main()
{
	cin >> n >> m;
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	BFS(1);
	int num = 0, dist = 0, cnt = 0,tmp=0;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]>tmp)
		{
			tmp = visited[i];
			num = i;
			dist = visited[i];
			cnt = 1;
		}
		else if(visited[i]==tmp)
		{
			cnt++;
			if (num > i)
				num = i;
		}
	}
	cout << num << ' ' << dist << ' ' << cnt;
	return 0;
}