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

int Arr[6][6];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int res = 0;
bool visit[1000000];
void DFS(int y,int x,int cnt, string str)
{
	if(cnt==6)
	{
		if(!visit[stoi(str)])
		{
			res++;
			visit[stoi(str)] = true;
		}
		return;
	}

	for(int i=0;i<4;i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if(nx>=0&&ny>=0&&nx<5&&ny<5)
		{
			DFS(ny, nx, cnt + 1, str + to_string(Arr[ny][nx]));
		}
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> Arr[i][j];

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			DFS(i, j, 0, "");

	cout << res;
	return 0;
}