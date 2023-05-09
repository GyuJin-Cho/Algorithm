#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
int M, N, K;

bool visit[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int cnt;
void DFS(int y, int x)
{
	cnt++;
	visit[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(ny<M&&nx<N&&ny>=0&&nx>=0)
		{
			if(!visit[ny][nx]&&arr[ny][nx]==0)
			{
				DFS(ny, nx);
			}
		}
	}

}

int main()
{
	cin >> M >> N >> K;

	int a, b, c, d;

	for(int i=0;i<K;i++)
	{
		cin >> a >> b >> c >> d;

		for(int i=b;i<d;i++)
		{
			for(int j=a;j<c;j++)
			{
				arr[i][j] = 1;
			}
		}

	}
	int ans = 0;
	vector<int> arrans;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cnt = 0;
			if(!visit[i][j]&&arr[i][j]==0)
			{
				DFS(i, j);
				ans++;
			}
			if(cnt!=0)
				arrans.push_back(cnt);
		}
	}
	cout << ans << '\n';
	sort(arrans.begin(), arrans.end());
	for(int i : arrans)
	{
		cout << i << ' ';
	}
	return 0;
}