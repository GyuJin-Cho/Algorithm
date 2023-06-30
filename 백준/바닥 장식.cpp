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

int N, M, ans = 0;
vector<vector<char>> arr;
vector<vector<bool>>visited;

void DFS(int y, int x, bool check)
{
	visited[y][x] = true;
	if(check)
	{
		if(x + 1 < M)
		{
			if(!visited[y][x+1]&&arr[y][x+1]=='-')
			{
				DFS(y, x + 1, true);
			}
		}
	}
	else
	{
		if (y + 1 < N)
		{
			if (!visited[y+1][x] && arr[y+1][x] == '|')
			{
				DFS(y + 1, x, false);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	arr.resize(N);
	visited.resize(N);
	for(int i=0;i<N;i++)
	{
		arr[i].resize(M);
		visited[i].resize(M);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];

	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr[i][j]=='-'&&!visited[i][j])
			{
				DFS(i, j,true);
				ans++;
			}
			else if(arr[i][j]=='|'&&!visited[i][j])
			{
				DFS(i, j, false);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}