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

class shark
{
public:
	int m, s, d;
	shark(int m, int s, int d) : m(m), s(s), d(d) {}
	shark() : m(0), s(0), d(0){}
};
int dx[] = { 0,1,1,1,0,-1,-1,-1 };
int dy[] = { -1,-1,0,1,1,1,0,-1 };
int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<vector<shark>>> a(n, vector<vector<shark>>(n));
	for (int i = 0; i < m; i++)
	{
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		r--;
		c--;
		a[r][c].push_back(shark(m, s, d));
	}

	for (int l = 0; l < k; l++)
	{
		vector<vector<vector<shark>>> b(n, vector<vector<shark>>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (auto Shark : a[i][j])
				{
					int y = i + dy[Shark.d] * Shark.s;
					int x = j + dx[Shark.d] * Shark.s;
					y = (y % n + n) % n;
					x = (x % n + n) % n;
					b[y][x].push_back(Shark);
				}
			}
		}
		a = b;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(a[i][j].size()>1)
				{
					int totalM = 0;
					int totalS = 0;
					int cnt = a[i][j].size();
					int compareD = a[i][j][0].d % 2;
					int resultD = 0;
					for(auto Shark : a[i][j])
					{
						if(Shark.d%2!=compareD)
						{
							resultD = 1;
						}
						totalM += Shark.m;
						totalS += Shark.s;
					}
					a[i][j].clear();
					int sharkM = totalM / 5;
					int sharkS = totalS / cnt;
					if(sharkM>0)
					{
						for(int dir=0;dir<4;dir++)
						{
							a[i][j].push_back(shark(sharkM, sharkS, dir * 2 + resultD));
						}
					}
				}
			}
		}
	}
	int answer = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(auto Shark : a[i][j])
			{
				answer += Shark.m;
			}
		}
	}
	cout << answer;
	return 0;
}