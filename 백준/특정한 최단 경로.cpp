#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<pair<int, int>> V[801];
vector<int> Dist;
int N, E;
const int INF = 217400000;
void Dijkstra(int x)
{
	Dist.clear();
	Dist.resize(N + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	Dist[x] = 0;
	pq.push(make_pair(0, x));

	while (!pq.empty())
	{
		int Cur = pq.top().second;
		int Cost = pq.top().first;
		pq.pop();
		if(Dist[Cur]<Cost)
			continue;
		for (int i = 0; i < V[Cur].size(); i++)
		{
			int nCost = V[Cur][i].second;
			int Next = V[Cur][i].first;
			
			if (Dist[Next] > nCost + Cost)
			{
				Dist[Next] = nCost + Cost;
				pq.push(make_pair(Dist[Next], Next));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int v, e, c;
		cin >> v >> e >> c;
		V[v].push_back(make_pair(e, c));
		V[e].push_back(make_pair(v, c));
	}
	int v1, v2;
	cin >> v1 >> v2;

	Dijkstra(1);
	int OneToV1 = Dist[v1];
	int OneToV2 = Dist[v2];

	Dijkstra(v1);
	int V1ToV2 = Dist[v2];
	int V1ToN = Dist[N];

	Dijkstra(v2);
	int V2ToN = Dist[N];

	int ans;

	ans = min(INF, OneToV1 + V1ToV2 + V2ToN);
	ans = min(ans, OneToV2 + V1ToV2 + V1ToN);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}