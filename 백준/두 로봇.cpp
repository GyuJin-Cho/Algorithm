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
int n, m, c;
vector<pair<int,int>> v[100001];
bool visit[100001];
void DFS(int x,int sum,int maxValue)
{
	if(x==c)
	{
		cout << sum - maxValue;
		exit(0);
	}

	for(int i=0;i<v[x].size();i++)
	{
		if(!visit[v[x][i].first])
		{
			visit[x] = true;
			DFS(v[x][i].first, v[x][i].second + sum, max(v[x][i].second, maxValue));
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> c;
	
	for(int i=0;i<n-1;i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(make_pair(y, z));
		v[y].push_back(make_pair(x, z));
	}
	DFS(m, 0,0);

	return 0;
}