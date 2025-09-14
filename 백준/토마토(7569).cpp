#include<iostream>
#include<queue>

using namespace std;

class Node
{
public:
	Node() {}
	Node(int _h, int _y, int _x) : h(_h), y(_y), x(_x) {}
	int h;
	int y;
	int x;
};

int M, N, H;
int Tomato[101][101][101];
int ch[101][101][101];
int dy[] = { 0,1,0,-1,0,0 };
int dx[] = { 1,0,-1,0,0,0 };
int dh[] = { 0,0,0,0,-1,1 };
bool visited[101][101][101];
queue<Node> q;

void BFS()
{
	while (!q.empty())
	{
		Node Now = q.front();
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nh = dh[i] + Now.h;
			int ny = dy[i] + Now.y;
			int nx = dx[i] + Now.x;
			if (nh >= 0 && ny >= 0 && nx >= 0 && nh < H && ny < N && nx < M)
			{
				if (!visited[nh][ny][nx] && Tomato[nh][ny][nx] == 0)
				{
					Tomato[nh][ny][nx] = 1;
					ch[nh][ny][nx] = ch[Now.h][Now.y][Now.x] + 1;
					visited[nh][ny][nx] = true;
					q.push(Node(nh, ny, nx));
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				cin >> Tomato[i][j][z];
				if (Tomato[i][j][z] == 1)
				{
					visited[i][j][z] = true;
					q.push(Node(i, j, z));
					ch[i][j][z] = 0;
				}
			}
		}
	}

	BFS();

	int ans = -217400000;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				if (Tomato[i][j][z] == 0)
				{
					cout << -1;
					return 0;
				}
				ans = max(ch[i][j][z], ans);
			}
		}
	}

	cout << ans;

	return 0;
}