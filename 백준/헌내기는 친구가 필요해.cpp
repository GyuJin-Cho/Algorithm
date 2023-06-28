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
int N, M;
char Map[601][601];
bool visited[601][601];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int ans = 0;
void DFS(int y, int x)
{
	visited[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny>=0&&nx>=0&&ny<N&&nx<M)
		{
			if(!visited[ny][nx]&&Map[ny][nx]=='O')
			{
				DFS(ny, nx);
			}
			else if (!visited[ny][nx] && Map[ny][nx] == 'P')
			{
				DFS(ny, nx);
				ans++;
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int y, x;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];
			if(Map[i][j]=='I')
			{
				y = i;
				x = j;
			}
		}

	}

	DFS(y, x);
	if (ans == 0)
	{
		cout << "TT";
		return 0;
	}
	cout << ans;
	return 0;
}