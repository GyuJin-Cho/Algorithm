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

using namespace std;
vector<int> Arr[300001];
bool visit[300001];
struct node
{
	int Dist;
	int cnt;
};
vector<int> BFS(const int& K,const int& X)
{
	vector<int>ans;
	visit[X] = true;
	queue<node> q;
	q.push({X,0});
	while(!q.empty())
	{
		node n = q.front();
		if (n.cnt == K)
		{
			ans.push_back(n.Dist);
		}
		q.pop();
		for(int i=0;i<Arr[n.Dist].size();i++)
		{
			int Next = Arr[n.Dist][i];
			if (!visit[Next])
			{
				visit[Next] = true;
				q.push({ Next,n.cnt + 1 });
			}
		}
	}
	return ans;
}
int main()
{
	int N, M, K, X;
	cin >> N >> M >> K >> X;
	int s, e;
	for(int i=0;i<M;i++)
	{
		cin >> s >> e;
		Arr[s].push_back(e);
	}
	vector<int>ans = BFS(K,X);
	if (ans.size() == 0)
		cout << -1;
	else
	{
		sort(ans.begin(), ans.end());
		for (int i : ans)
			cout << i << '\n';
	}
	return 0;
}