#include<iostream>
#include<vector>

using namespace std;
#define INTMIN -2147000000
int answer = INTMIN;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[21][21];
char Alpabet[21][21];
bool AlpabetCheck[26];
int R, C;
void DFS(int Y, int X,int sum)
{
	answer = max(sum, answer);
	for(int i=0;i<4;i++)
	{
		int ny = dy[i] + Y;
		int nx = dx[i] + X;
		if(ny>0&&nx>0&&ny<=R&&nx<=C)
		{
			if (!visit[ny][nx])
			{
				if (!AlpabetCheck[Alpabet[ny][nx]-'A'])
				{
					AlpabetCheck[Alpabet[ny][nx] - 'A'] = true;
					visit[ny][nx] = true;
					DFS(ny, nx, sum + 1);
					visit[ny][nx] = false;
					AlpabetCheck[Alpabet[ny][nx] - 'A'] = false;
				}
				
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> R >> C;
	for(int i=1;i<=R;i++)
	{
		for(int j=1;j<=C;j++)
		{
			cin >> Alpabet[i][j];
		}
	}
	vector<char> v;
	v.push_back(Alpabet[1][1]);
	visit[1][1] = true;
	AlpabetCheck[Alpabet[1][1] - 'A'] = true;
	DFS(1, 1,1);
	
	printf("%d", answer);
}