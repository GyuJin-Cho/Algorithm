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
int n, l, r;
int a[51][51];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool BFS(const int&l, const int&r)
{
	vector<vector<bool>> c(n, vector<bool>(n, false));
	bool ok = false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(!c[i][j])
			{
				queue<pair<int, int>> q;
				q.push({ i,j });
				c[i][j] = true;
				stack<pair<int, int>> s;
				s.push({ i,j });
				int sum = a[i][j];
				while(!q.empty())
				{
					int y, x;
					tie(y, x) = q.front();
					q.pop();
					for(int k=0;k<4;k++)
					{
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx>=0&&nx<n&&ny>=0&&ny<n)
						{
							if(c[ny][nx])
								continue;
							int diff = a[ny][nx] - a[y][x];
							if (diff < 0)
								diff = -diff;
							if(l<=diff&&diff<=r)
							{
								q.push({ ny,nx });
								s.push({ ny,nx });
								c[ny][nx] = true;
								ok = true;
								sum += a[ny][nx];
							}
						}
					}
				}
				int val = sum / s.size();
				while(!s.empty())
				{
					int y, x;
					tie(y, x) = s.top();
					s.pop();
					a[y][x] = val;
				}
			}
		}
	}
	return ok;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int answer = 0;
	while(1)
	{
		if(BFS(l,r))
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	cout << answer;
	return 0;
}