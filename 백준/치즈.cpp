#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

struct node
{
	int y;
	int x;
};

bool visit[101][101];
int map[101][101];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int r, c;
int cnt, area;

void BFS()
{
	queue<node> q;
	queue<node> temp;
	q.push({ 0,0 });
	while(!q.empty())
	{
		area = q.size();
		while(!q.empty())
		{
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if(nx>=0&&ny>=0&&nx<c&&ny<r)
				{
					if(!visit[ny][nx]&&map[ny][nx]==1)
					{
						temp.push({ ny,nx });
					}
					else if(!visit[ny][nx]&&map[ny][nx]==0)
					{
						q.push({ ny,nx });
					}
					visit[ny][nx] = true;
				}
			}
		}
		while(!temp.empty())
		{
			q.push(temp.front());
			temp.pop();
		}
		cnt++;
	}
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];
	visit[0][0] = true;
	BFS();
	cout << cnt - 1 << '\n';
	cout << area << '\n';
	return 0;
}