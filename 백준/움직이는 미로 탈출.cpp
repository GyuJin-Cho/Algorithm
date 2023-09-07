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
vector<string>v(8);
int dx[] = { 1,1,0,-1,-1,-1,0,1,0};
int dy[] = { 0,1,1,1,0,-1,-1,-1,0};
bool check[8][8][9];
class node
{
public:
	int y;
	int x;
	int t;

	node(int y, int x, int t) : y(y), x(x), t(t){}
	node()
	{
		y = 0;
		x = 0;
		t = 0;
	}
};

void BFS()
{
	queue<node> q;
	check[7][0][0] = true;
	q.push(node(7, 0, 0));
	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		if(n.x==7&&n.y==0)
		{
			cout << 1;
			return;
		}
		for(int i=0;i<9;i++)
		{
			int nx = n.x + dx[i];
			int ny = n.y + dy[i];
			int nt = min(n.t + 1, 8);
			if(ny>=0&&ny<8&&nx>=0&&nx<8)
			{
				if (ny - n.t >= 0 && v[ny - n.t][nx] == '#')
					continue;
				if (ny - n.t - 1 >= 0 && v[ny - n.t - 1][nx] == '#')
					continue;
				if(!check[ny][nx][nt])
				{
					check[ny][nx][nt] = true;
					q.push(node(ny, nx, nt));
				}
			}
		}
	}
	cout << 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 0; i < 8; i++)
		cin >> v[i];
	BFS();;
	return 0;
}