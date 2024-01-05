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
constexpr int MAX = 105;
constexpr int INF = 1e9;
int N, M, R;
vector<pair<int, int>> Edge[MAX];
int InformationItem[MAX];
int Dist[MAX];

int Dijikstra(int start)
{
	for (int i = 1; i <= N; i++)
		Dist[i] = INF;
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	Dist[start] = 0;
	while(!pq.empty())
	{
		int nowcost = pq.top().first;
		int nowdist = pq.top().second;
		pq.pop();

		for(int i=0;i<Edge[nowdist].size();i++)
		{
			int nextcost = Edge[nowdist][i].second;
			int nextdist = Edge[nowdist][i].first;

			if(nextcost+nowcost<Dist[nextdist])
			{
				Dist[nextdist] = nextcost + nowcost;
				pq.push({ Dist[nextdist],nextdist });
			}
		}
	}

	int sum = 0;

	for(int i=1;i<=N;i++)
	{
		if (Dist[i] <= M)
			sum += InformationItem[i];
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for(int i=1;i<=N;i++)
	{
		cin >> InformationItem[i];
	}

	for(int i=0;i<R;i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		Edge[u].push_back({ v,c });
		Edge[v].push_back({ u,c });
	}

	int ans = 0;
	for(int i=1;i<=N;i++)
	{
		ans = max(ans, Dijikstra(i));
	}
	cout << ans;
	return 0;
}
