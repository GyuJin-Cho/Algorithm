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

int N, M,ans=0;
int arr[1001][1001];
bool visited[1001][1001];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int arr2[1001][1001];
void DFS(int y, int x)
{
	visited[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if(ny>=0&&nx>=0&&ny<N&&nx<M)
		{
			if(!visited[ny][nx]&&arr2[ny][nx]==255)
			{
				DFS(ny, nx);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int y = 0, x = 0;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		y++;
		x = 0;
		int a;
		for (int j = 1; j <= M * 3; j++)
		{
			cin >> a;
			sum += a;
			if(j%3==0)
			{
				x++;
				arr[y][x] = sum;
				sum = 0;
			}
		}
	}
		
	int T;
	cin >> T;
	y = -1, x = -1;
	for(int i=1;i<=N;i++)
	{
		y++;
		x = -1;
		for(int j=1;j<=M;j++)
		{
			x++;
			if(T<=(arr[i][j]/3))
			{
				arr2[y][x] = 255;
			}
			else
			{
				arr2[y][x] = 0;
			}
		}
	}
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(arr2[i][j]==255&&!visited[i][j])
			{
				DFS(i, j);
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}