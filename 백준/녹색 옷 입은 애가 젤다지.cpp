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
int Arr[126][126];
int Dist[126][126];
constexpr int MAX = 1e8;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int n;

void Init()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			Dist[i][j] = MAX;
}

void Dijkstra()
{
	priority_queue <pair<int,pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
	pq.push({ Arr[0][0],{0,0} });
	Dist[0][0] = Arr[0][0];
	while(!pq.empty())
	{
		int NowNodeX = pq.top().second.second;
		int NowNodeY = pq.top().second.first;
		int NowCost = pq.top().first;
		pq.pop();
		

		for(int i=0;i<4;i++)
		{
			int nx = NowNodeX + dx[i];
			int ny = NowNodeY + dy[i];

			if(nx>-1&&ny>-1&&nx<n&&ny<n)
			{
				if(Arr[ny][nx]+NowCost < Dist[ny][nx])
				{
					Dist[ny][nx] = Arr[ny][nx] + NowCost;
					pq.push({ Dist[ny][nx],{ny,nx} });
				}
			}
		}
	}
}

int main()
{
	int cnt = 1;
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		Init();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> Arr[i][j];
		Dijkstra();

		cout <<"Problem "<< cnt << ": " << Dist[n - 1][n - 1] << '\n';
		cnt++;
	}

	return 0;
}