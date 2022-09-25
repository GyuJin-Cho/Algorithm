#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int y=0;
	int x=0;
	int ud=0;
	int ans=0;
};

int Map[101][101][101] = { 0, };

int dx[] = { 1,0,-1,0,0,0 };
int dy[] = { 0,1,0,-1,0,0 };
int UD[] = {0,0,0,0,1,-1 };

queue<node> q;
int BFS(int M, int N, int H,bool check)
{
	if (check)
		return 0;

	int answer = 0;
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		n.ans++;
		answer = n.ans;
		for (int i = 0; i < 6; i++)
		{
			int nx = n.x + dx[i];
			int ny = n.y + dy[i];
			int nUD = n.ud + UD[i];
			if (nx >= 0 && ny >= 0 && nUD>=0 && nx < M && ny < N && nUD<H)
			{
				if (Map[nUD][ny][nx] == 0 && Map[nUD][ny][nx] != -1)
				{
					Map[nUD][ny][nx] = 1;
					q.push({ ny,nx,nUD,answer });
				}
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				if (Map[i][j][z] == 0)
					return -1;
			}
		}
	}
	return answer-1;
}

int main()
{
	int M, N, H;
	cin >> M >> N >> H;
	bool check = true;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int z = 0; z < M; z++)
			{
				int a;
				cin >> a;
				Map[i][j][z] = a;
				if (a == 1)
				{
					q.push({ j,z,i,0 });
				}
				if (a == 0)
				{
					check = false;
				}
			}
		}
	}

	cout<<BFS(M, N, H, check);

	return 0;
}