#include<iostream>
#include<queue>
#include<vector>

using namespace std;
#define MAX 2417000000
vector<pair<int, int>> V[1002];
bool Visit[1002];

int MST()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>	pq;
	pq.push({ 0,1 });
	int answer = 0;
	while(!pq.empty())
	{
		int Cost = pq.top().first;
		int Cur = pq.top().second;
		pq.pop();
		if (Visit[Cur])
			continue;
		Visit[Cur] = true;
		answer += Cost;
		for(int i=0;i<V[Cur].size();i++)
		{
			if(!Visit[V[Cur][i].first])
			{
				pq.push({ V[Cur][i].second,V[Cur][i].first });
			}
		}

	}
	return answer;
}

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	int s, e, cost;
	for(int i=0;i<M;i++)
	{
		cin >> s >> e >> cost;
		V[s].push_back({ e,cost });
		V[e].push_back({ s,cost });

	}
	cout << MST();
	return 0;
}