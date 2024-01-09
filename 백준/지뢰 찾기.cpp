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
char Board[11][11];
char Search[11][11];
int dx[] = { 1,1,0,-1,-1,-1,0,1 };
int dy[] = { 0,1,1,1,0,-1,-1,-1 };
char ans[11][11];
int main()
{
	int n;
	cin >> n;
	bool flag = false;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> Board[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> Search[i][j];
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(Search[i][j]=='x')
			{
				int cnt = 0;
				if(Board[i][j]=='*')
				{
					flag = true;
				}
				for (int direction = 0; direction < 8; direction++)
				{
					int ny = i + dy[direction];
					int nx = j + dx[direction];
					
					if(ny>=0&&nx>=0&&ny<n&&nx<n)
					{
						if(Board[ny][nx]=='*')
						{
							cnt++;
						}
					}
				}
				if (cnt == 0)
				{
					ans[i][j] = '0';
				}
				else
				{
					ans[i][j] = cnt + '0';
				}
			}
			else
			{
				ans[i][j] = '.';
			}
		}
	}

	if(flag)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if (Board[i][j] == '*')
					ans[i][j] = '*';
			}
		}
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << ans[i][j];
		}
		cout << '\n';
	}

	return 0;
}