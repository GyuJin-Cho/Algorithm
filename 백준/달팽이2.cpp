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
int a[101][101];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int main()
{
	int n, m;
	cin >> n >> m;
	int x = 0;
	int y = 0;
	a[0][0] = n * m;
	int k = 0;
	int answer = 0;
	for(int i=n*m-1;i>=1;i--)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(0<=nx&&nx<m&&0<=ny&&ny<n&&a[ny][nx]==0)
		{
			
		}		
		else
		{
			k = (k + 1) % 4;
			nx = x + dx[k];
			ny = y + dy[k];
			answer++;
		}
		a[ny][nx] = i;
		x = nx;
		y = ny;
	}
	cout << answer;
	return 0;
}