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
#include<cstring>

using namespace std;
#define MAX 101
int n, m, t;
int arr[MAX][MAX];
bool visited[MAX][MAX][2];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

struct node
{
	int y;
	int x;
	bool sword;
	int cnt;
};

void BFS(int y,int x)
{
	visited[y][x][0] = true;
	queue<node> q;
	q.push({ y,x,false,0 });
	while(!q.empty())
	{
		node no = q.front();
		q.pop();
		if(no.y==n-1&&no.x==m-1)
		{
			cout << no.cnt;
			return;
		}
		if(no.cnt>t)
		{
			cout << "Fail";
			return;
		}

		for(int i=0;i<4;i++)
		{
			int ny = no.y + dy[i];
			int nx = no.x + dx[i];

			if(ny>=0&&nx>=0&&ny<n&&nx<m)
			{
				if(no.sword)
				{
					if (!visited[ny][nx][1])
					{
						q.push({ ny,nx,true,no.cnt + 1 });
						visited[ny][nx][1] = true;
					}
				}
				else
				{
					if (!visited[ny][nx][0]&& arr[ny][nx] != 1)
					{
						if(arr[ny][nx]==2)
						{
							q.push({ ny,nx,true,no.cnt + 1 });
							visited[ny][nx][1] = true;
						}
						else
						{
							q.push({ ny,nx,false,no.cnt + 1 });
							visited[ny][nx][0] = true;
						}
					}
				}
				
			}
		}

	}
	cout << "Fail";
}

int main()
{
	cin >> n >> m >> t;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}

	BFS(0, 0);
	
	return 0;
}