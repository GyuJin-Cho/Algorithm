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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for(int i=0;i<n;i++)
	{
		int s, e;
		cin >> s >> e;
		v.push_back({ s,e });
	}
	sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2)
		{
			if (p1.first == p2.first)
				return p1.second < p2.second;
			return p1.first < p2.first;
		});
	priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(v[0].second);
	for(int i=1;i<n;i++)
	{
		pq.push(v[i].second);
		if (pq.top() <= v[i].first)
			pq.pop();
	}
	cout << pq.size();
	return 0;
}