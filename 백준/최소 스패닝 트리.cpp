#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<pair<int, int>> N[10001];

bool visit[10001] = { false, };
void MST()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	long long answer = 0;
	while (!pq.empty())
	{
		int Cost = pq.top().first;
		int Now_node = pq.top().second;
		pq.pop();
		if (visit[Now_node])
		{
			continue;
		}
		visit[Now_node] = true;
		answer += Cost;
		for (int i = 0; i < N[Now_node].size(); i++)
		{
			if (!visit[N[Now_node][i].first])
			{
				int Next_Node = N[Now_node][i].first;
				int Next_Cost = N[Now_node][i].second;
				pq.push(make_pair(Next_Cost, Next_Node));
			}

		}
	}
	cout << answer;
}

int main()
{
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B, C;

		cin >> A >> B >> C;
		N[A].push_back(make_pair(B, C));
		N[B].push_back(make_pair(A, C));
	}


	MST();
	return 0;
}