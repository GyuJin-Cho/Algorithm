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
#define MAX 201

int R, C, N;
int BoomTime[MAX][MAX];
char MAP[MAX][MAX];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

void InstallBoom(int time)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(MAP[i][j]=='O')
				continue;
			MAP[i][j] = 'O';
			BoomTime[i][j] = time + 3;
		}
	}
}

void DeleteBoom(int time)
{
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			if(BoomTime[i][j]==time)
			{
				for(int k=0;k<4;k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];

					if(nx>=0&&ny>=0&&nx<C&&ny<R)
					{
						if (MAP[ny][nx] == 'O')
							MAP[ny][nx] = '.';
					}
				}
				MAP[i][j] = '.';
				BoomTime[i][j] = 0;
			}
		}
	}
}

int main()
{
	cin >> R >> C >> N;
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cin >> MAP[i][j];
			if(MAP[i][j]=='O')
			{
				BoomTime[i][j] = 3;
			}
		}
	}
	int time = 2;
	while(1)
	{
		if (time == N + 1)
			break;
		if(time%2==0)
		{
			InstallBoom(time);
		}
		else
		{
			DeleteBoom(time);
		}
		time++;
	}

	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
		{
			cout << MAP[i][j];
		}
		cout << '\n';
	}

	return 0;
}