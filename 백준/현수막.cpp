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
bool visit[252][252];
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };


void DFS(int y, int x, vector<vector<int>>& arr)
{
	visit[y][x] = true;

	for(int i=0;i<8;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny>=0&&nx>=0&&ny<N&&nx<M)
		{
			if(!visit[ny][nx]&&arr[ny][nx]==1)
			{
				DFS(ny, nx, arr);
			}
		}
	}

}

int main()
{
	
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(!visit[i][j]&&arr[i][j]==1)
			{
				DFS(i, j, arr);
				ans++;
			}
		}
	}
	cout << ans;



	return 0;
}