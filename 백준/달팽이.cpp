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
int a[1001][1001];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int m;
	cin >> m;
	int x = (n - 1) / 2;
	int y = (n - 1) / 2;
	a[y][x] = 1;
	int num = 2;

	for(int size=3;size<=n;size+=2)
	{
		x += dx[3];
		y += dy[3];
		a[y][x] = num++;
		for(int k=0;k<4;k++)
		{
			int l = size - 1;
			if (k == 0)
				l -= 1;
			for(int i=0;i<l;i++)
			{
				x += dx[k];
				y += dy[k];
				a[y][x] = num++;
			}
		}
	}

	x = 0;
	y = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << a[i][j] << ' ';
			if(a[i][j]==m)
			{
				y = i + 1;
				x = j + 1;
			}
		}
		cout << '\n';
	}
	cout << y << ' ' << x;
	return 0;
}