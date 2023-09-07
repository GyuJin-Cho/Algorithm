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

struct node
{
	int y;
	int x;
	int cnt;
	int Breaking;
};
int Map[1001][1001];
bool visit[1001][1001][11];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int N, M,K;
void BFS()
{
	queue<node> q;
	q.push({ 0,0,1 ,0 });
	visit[0][0][0] = true;
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		if (n.y == N - 1 && n.x == M - 1)
		{
			cout << n.cnt;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = n.y + dy[i];
			int nx = n.x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < N && nx < M)
			{
				if (n.Breaking+1<=K&&Map[ny][nx] == 1&&!visit[ny][nx][n.Breaking])
				{

					q.push({ ny,nx,n.cnt + 1,n.Breaking + 1 });
					visit[ny][nx][n.Breaking] = true;

				}
				else if (Map[ny][nx] == 0 && !visit[ny][nx][n.Breaking])
				{
					q.push({ ny,nx,n.cnt + 1,n.Breaking });
					visit[ny][nx][n.Breaking] = true;

				}
			}
		}
	}
	cout << -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M>>K;

	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			Map[i][j] = s[j] - 48;
		}

	}
	BFS();
	return 0;
}