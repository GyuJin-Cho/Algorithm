#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#define MAX 223372036854775807
using namespace std;

vector<pair<int, int>> V[1001];
vector<long long> Dist;

void Dijkstra(int start, int end)
{
	priority_queue < pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
	pq.push(make_pair(0, start));
	Dist[start] = 0;

	while (!pq.empty())
	{
		long long Cost = pq.top().first;
		long long Cur = pq.top().second;
		pq.pop();

		if (Cost > Dist[Cur])
			continue;

		for (int i = 0; i < V[Cur].size(); i++)
		{
			long long N_Cost = V[Cur][i].second;
			long long N_Cur = V[Cur][i].first;

			if (Dist[N_Cur] > N_Cost + Cost)
			{
				Dist[N_Cur] = N_Cost + Cost;
				pq.push({ N_Cost + Cost,N_Cur });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	Dist.resize(N + 1, MAX);
	for (int i = 0; i < M; i++)
	{
		int v, e, cost;
		cin >> v >> e >> cost;
		V[v].push_back(make_pair(e, cost));
	}

	int Start, Goal;
	cin >> Start >> Goal;
	
	Dijkstra(Start, Goal);

	cout << Dist[Goal];

	return 0;
}