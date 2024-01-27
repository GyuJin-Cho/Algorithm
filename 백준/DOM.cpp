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

int N, M, T;
vector<int> v[100001];
int cnt = -1;
bool visited[100001];
int DFS(int T)
{
	visited[T] = true;

	if (v[T].empty())
		return 0;

	int nx = v[T][0];

	if (visited[nx])
		return -1;

	int deep = DFS(nx);

	return deep == -1 ? -1 : deep + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;

	for (int i = 0; i < N; i++)
	{
		int like, hate;
		cin >> like >> hate;
		if (v[hate].size() == 0)
			v[hate].push_back(like);
	}
	cout<<DFS(T);
	return 0;
}