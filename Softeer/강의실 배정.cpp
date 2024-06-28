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
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end());
	
	int cur = v[0].first;
	int cnt = 1;
	for (int i = 1; i < n; i++)
	{
		if (cur <= v[i].second)
		{
			cur = v[i].first;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}