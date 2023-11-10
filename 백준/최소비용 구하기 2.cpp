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
constexpr int MAX = 100000001;
vector<pair<int,int>> V[1001];
int Dist[1001];
int BeforeCity[1001];
int n,m,s, e;
void Dijkstra(const int& start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start });
	Dist[start] = 0;
	while(!pq.empty())
	{
		int NowCost = pq.top().first;
		int NowNode = pq.top().second;
		pq.pop();
		if(NowCost>Dist[NowNode])
		{
			continue;
		}
		for(int i=0;i<V[NowNode].size();i++)
		{
			int nc = V[NowNode][i].second;
			int nn = V[NowNode][i].first;
			if(nc+NowCost<Dist[nn])
			{
				Dist[nn] = nc + NowCost;
				pq.push({Dist[nn],nn });
				BeforeCity[nn] = NowNode;
			}
		}
	}

}

int main()
{
	cin >> n;
	cin >> m;
	fill(Dist, Dist + n, MAX);
	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b>>c;
		V[a].push_back({b,c});
	}
	
	cin >> s >> e;
	Dijkstra(s);
	cout << Dist[e]<<'\n';
	vector <int> arr;
	arr.push_back(e);
	int val = BeforeCity[e];
	while (val)
	{
		arr.push_back(val);
		val = BeforeCity[val];
	}

	cout << arr.size() << '\n';
	for (int i = arr.size() - 1; i >= 0; i--) 
	{
		cout << arr[i] << ' ';
	}

	return 0;
}