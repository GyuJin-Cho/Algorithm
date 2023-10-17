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
int arr[101][101];
bool visit[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n, m;

class node
{
public:
	int y;
	int x;
	int cnt;
	node(int y, int x,int cnt) : y(y), x(x),cnt(cnt){}
	node():	y(0) , x(0),cnt(0){}
	
};

void BFS(int y, int x)
{
	visit[y][x] = true;
	queue<node> q;
	q.push(node(y,x,0));

	while(!q.empty())
	{
		node no = q.front();
		q.pop();
		if(no.y==n-1&&no.x==m-1)
		{
			cout << no.cnt+1;
			return;
		}
		for(int i=0;i<4;i++)
		{
			int ny = dy[i] + no.y;
			int nx = dx[i] + no.x;
			if(ny<n&&nx<m&&ny>=0&&nx>=0)
			{
				if(!visit[ny][nx]&&arr[ny][nx]==1)
				{
					q.push(node(ny, nx, no.cnt + 1));
					visit[ny][nx] = true;
				}
			}
		}
	}

}

int main()
{
	cin >> n >> m;
	string s;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = (s[j] - 48);
		}
	}

	BFS(0, 0);

	return 0;
}