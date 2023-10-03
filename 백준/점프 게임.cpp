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

int main()
{
	int n, k;
	cin >> n >> k;
	vector<string> a(2);
	for(int i=0;i<2;i++)
	{
		cin >> a[i];
	}
	int dirsx[] = { 0,0,1 };
	int dirsy[] = { 1,-1,k };
	vector<pair<int, int>> dirs = { {0,1},{0,-1},{1,k} };
	vector<vector<int>> d(2, vector<int>(n, -1));
	queue<pair<int, int>>q;
	d[0][0] = 0;
	q.push({ 0,0 });
	bool ch = false;
	while(!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for(int i=0;i<3;i++)
		{
			int dx = dirsx[i];
			int dy = dirsy[i];
			int nx = (x + dx) % 2;
			int ny = y + dy;
			if(ny>=n)
			{
				ch = true;
				break;
			}
			if(ny<0)
				continue;
			if(d[nx][ny]!=-1)
				continue;
			if(a[nx][ny]=='0')
				continue;
			if(ny<d[x][y]+1)
				continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({ nx,ny });
		}
		if (ch)
			break;
	}
	cout << (ch ? 1 : 0);
	return 0;
}