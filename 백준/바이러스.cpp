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
vector<int> arr[101];
bool visited[101];
int cnt;
void DFS(int v)
{
	visited[v] = true;
	cnt++;
	for(int i=0;i<arr[v].size();i++)
	{
		if(!visited[arr[v][i]])
		{
			DFS(arr[v][i]);
		}
	}
}

int main()
{
	int n, m;
	cin >> n;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int u, v;
		cin >> u >> v;
		arr[u].push_back(v);
		arr[v].push_back(u);
	}

	DFS(1);
	cout << cnt-1;

	return 0;
}