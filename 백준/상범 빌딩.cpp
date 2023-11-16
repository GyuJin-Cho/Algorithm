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
int dx[] = { 1, 0, -1, 0, 0, 0 };
int dy[] = { 0, 1, 0, -1, 0, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
char arr[31][31][31];
bool visited[31][31][31];
int c, r, l;
int sz, sy, sx;
struct node
{
	int z;
	int y;
	int x;
	int cnt;
};
void BFS()
{
	queue<node> q;
	q.push({ sz,sy,sx,0 });
	visited[sz][sy][sx] = true;

	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		if(arr[n.z][n.y][n.x]=='E')
		{
			cout <<"Escaped in " << n.cnt <<" minute(s)." << '\n';
			return;
		}

		for(int i=0;i<6;i++)
		{
			int nz = dz[i] + n.z;
			int ny = dy[i] + n.y;
			int nx = dx[i] + n.x;
			if(nz<c&&ny<r&&nx<l&&nz>=0&&ny>=0&&nx>=0)
			{
				if(!visited[nz][ny][nx]&&arr[nz][ny][nx]!='#')
				{
					q.push({ nz,ny,nx,n.cnt + 1 });
					visited[nz][ny][nx] = true;
				}
			}
		}
	}
	cout << "Trapped!" << '\n';
}

int main()
{
	
	while(1)
	{
		cin >> c >> r >> l;
		if (c == 0 && r == 0 && l == 0)
			break;
		for (int z = 0; z < c; z++)
		{
			for (int y = 0; y < r; y++)
			{
				for (int x = 0; x < l; x++)
				{
					cin >> arr[z][y][x];
					if (arr[z][y][x] == 'S')
					{
						sz = z;
						sy = y;
						sx = x;
					}
				}
			}
		}
		BFS();
		memset(visited, false, sizeof(visited));
		memset(arr, '\0', sizeof(arr));
	}
	
	return 0;
}