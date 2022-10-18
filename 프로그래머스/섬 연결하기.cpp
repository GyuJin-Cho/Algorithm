#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;
bool visit[101] = { false, };
vector<pair<int, int>> N[101];
long long answer = 0;
void MST()
{
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 0));
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int Now_Node = pq.top().second;
		pq.pop();
		if (visit[Now_Node])
			continue;
		visit[Now_Node] = true;
		answer += cost;
		for (int i = 0; i < N[Now_Node].size(); i++)
		{
			if (!visit[N[Now_Node][i].first])
			{
				int Next_Node = N[Now_Node][i].first;
				int Next_Cost = N[Now_Node][i].second;
				pq.push(make_pair(Next_Cost, Next_Node));
			}
		}
	}
}

int solution(int n, vector<vector<int>> costs)
{
	
	for (int i = 0; i < costs.size(); i++)
	{
		int v = costs[i][0];
		int e = costs[i][1];
		int cost = costs[i][2];
		N[v].push_back(make_pair(e, cost));
		N[e].push_back(make_pair(v, cost));
	}
	MST();
	return answer;
}

int main()
{
	vector<vector<int>> costs = 
	{ 
		{0, 1, 1},
		{0, 2, 2},
		{1, 2, 5},
		{1, 3, 1},
		{2, 3, 8}
	};
	cout << solution(4, costs);

	return 0;
}