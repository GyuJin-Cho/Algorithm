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
int arr[26][26];
bool visit[26][26];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
vector<int> cnt;
int ans;
int n;
int sum = 0;
void DFS(int y, int x)
{
	sum++;
	visit[y][x] = true;
	for(int i=0;i<4;i++)
	{
		int ny = dy[i]+y;
		int nx = dx[i]+x;
		if(ny<n&&nx<n&&ny>=0&&nx>=0&&arr[ny][nx]==1&&!visit[ny][nx])
		{
			DFS(ny, nx);
		}
	}
}

int main()
{
	cin >> n;
	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			arr[i][j] = (s[j] - 48);
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(arr[i][j]==1&&!visit[i][j])
			{
				DFS(i, j);
				cnt.push_back(sum);
				sum = 0;
			}
		}
	}
	sort(cnt.begin(), cnt.end());
	cout << cnt.size() << '\n';
	for(int i: cnt)
	{
		cout << i << '\n';
	}
	return 0;
}