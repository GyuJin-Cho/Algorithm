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

vector<pair<int, long long>> V[10001];
const long long INF = 21740000;
bool visit[10001];
void MST()
{
	priority_queue < pair<long long, int>, vector <pair<long long, int>>, greater<pair<long long, int>>>pq;

	pq.push({ 0,1 });
	long long ans = 0;
	while(!pq.empty())
	{
		int pos, cost;
		tie(cost, pos) = pq.top();
		pq.pop();
		if(visit[pos])
			continue;
		visit[pos] = true;
		ans += cost;
		for(int i=0;i<V[pos].size();i++)
		{
			int nPos = V[pos][i].first;
			int nCost = V[pos][i].second;
			if(!visit[nPos])
			{
				pq.push({ nCost,nPos });
			}
		}

	}
	cout << ans;
}

int main()
{

	int v, e;
	cin >> v >> e;
	int x, y;
	long long d;
	for(int i=0;i<e;i++)
	{
		cin >> x >> y >> d;
		V[x].push_back({ y,d });
		V[y].push_back({ x,d });
	}

	MST();
	return 0;
}