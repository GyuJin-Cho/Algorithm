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

int M, N;
bool visited[1001][1001];
bool arr[1001][1001];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
bool Goal;

void DFS(int y,int x)
{
	visited[y][x] = true;
	if (y == M - 1)
	{
		Goal = true;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if(ny>=0&&nx>=0&&ny<M&&nx<N)
		{
			if(!visited[ny][nx]&&!arr[ny][nx])
			{
				DFS(ny, nx);
			}
		}
	}
}

int main()
{
	cin >> M >> N;
	string s;
	for (int i = 0; i < M; i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j] - 48;
		}
	}
		
			

	for (int j = 0; j < N; j++)
	{
		if(!arr[0][j]&&!visited[0][j])
		{
			DFS(0, j);
			if(Goal)
			{
				cout << "YES";
				return 0;
			}
		}
	}
	

	cout << "NO";

	return 0;
}