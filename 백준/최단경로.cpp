#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
using namespace std;


vector<pair<int,int>> v[300001];
vector<int> Dist;
vector<int> ans;
#define INF 2147483647
void answer(int start,int Max)
{
	priority_queue<pair<int, int>> pq;

	pq.push(make_pair(0, start));
	Dist[start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int Next = v[cur][i].first;
			int nCost = v[cur][i].second;

			if (Dist[Next] > cost + nCost)
			{
				Dist[Next] = cost + nCost;
				pq.push(make_pair(-Dist[Next], Next));
			}
		}
	}

	for (int i = 1; i <= Max; i++)
	{
		if (Dist[i] == INF)
		{
			cout << "INF" << endl;
			continue;
		}
		printf("%d\n",Dist[i]);
	}

}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	int V, E;
	scanf("%d%d", &V, &E);
	int start;
	scanf("%d", &start);

	int s, e, d;

	Dist.resize(V+1, INF);

	for (int i = 1; i <= E; i++)
	{
		scanf("%d%d%d", &s, &e, &d);
		v[s].push_back(make_pair(e,d));
	}

	answer(start,V);

	return 0;
}