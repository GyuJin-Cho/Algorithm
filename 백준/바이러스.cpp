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

void DFS(int Depth)
{
	visited[Depth] = true;
	cnt++;
	for (int i = 0; i < arr[Depth].size(); i++)
	{
		if (!visited[arr[Depth][i]])
		{
			DFS(arr[Depth][i]);
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
	}

	DFS(1);
	cout << cnt - 1;
	return 0;
}