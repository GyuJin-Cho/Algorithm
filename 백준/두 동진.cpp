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
int n, m;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int DFS(const vector<string>& a,int step ,int y1, int x1, int y2, int x2)
{
	if (step == 11)
		return -1;
	bool fail1 = false;
	bool fail2 = false;
	if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n)
		fail1 = true;
	if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n)
		fail2 = true;
	if (fail1 && fail2)
		return -1;
	if (fail1 || fail2)
		return step;
	int answer = -1;
	for(int k=0;k<4;k++)
	{
		int nx1 = x1 + dx[k];
		int nx2 = x2 + dx[k];
		int ny1 = y1 + dy[k];
		int ny2 = y2 + dy[k];
		if(nx1>=0&&nx1<m&&ny1>=0&&ny1<n&&a[ny1][nx1]=='#')
		{
			nx1 = x1;
			ny1 = y1;
		}
		if (nx2 >= 0 && nx2 < m && ny2 >= 0 && ny2 < n && a[ny2][nx2] == '#')
		{
			nx2 = x2;
			ny2 = y2;
		}

		int tmp = DFS(a, step+1, ny1, nx1, ny2, nx2);
		if (tmp == -1)
			continue;
		if (answer == -1 || answer > tmp)
			answer = tmp;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	vector<string> a(n);
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='o')
			{
				if (x1 == -1 && y1 == -1)
				{
					y1 = i;
					x1 = j;
				}
				else
				{
					y2 = i;
					x2 = j;
				}
				a[i][j] = '.';
			}
		}
	}
	cout << DFS(a, 0, y1, x1, y2, x2);
	return 0;
}