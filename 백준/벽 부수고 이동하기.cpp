#include<iostream>
#include<queue>

using namespace std;

struct node
{
	int y;
	int x;
	int cost;
	int Breaking;
};

int Map[1001][1001];
bool ch[1001][1001][2];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
void BFS(int& n, int& m)
{
	queue<node> q;
	q.push({ 1,1,1,false });
	ch[1][1][0] = true;
	
	while(!q.empty())
	{
		node Node = q.front();
		q.pop();
		if(Node.y==n&& Node.x==m)
		{
			cout << Node.cost;
			return;
		}

		for(int i=0;i<4;i++)
		{
			int ny = Node.y + dy[i];
			int nx = Node.x + dx[i];

			if(ny>0&&nx>0&&ny<=n&&nx<=m)
			{
				if(Map[ny][nx]==1&&Node.Breaking==0)
				{
					
					q.push({ ny,nx,Node.cost + 1,Node.Breaking+1 });
					ch[ny][nx][1] = true;
					
				}
				else if(Map[ny][nx]==0&&!ch[ny][nx][Node.Breaking])
				{
					q.push({ ny,nx,Node.cost + 1,Node.Breaking });
					ch[ny][nx][Node.Breaking] = true;
				
				}
			}
		}
	}
	cout << -1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	string s;

	for(int i=1;i<=n;i++)
	{
		cin >> s;
		for(int z=1;z<=s.size();z++)
		{
			Map[i][z] = s[z-1] - 48;

		}

	}
	
	BFS(n,m);
	return 0;
}