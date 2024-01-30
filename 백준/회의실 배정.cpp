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
			if (p1.second == p2.second)
				return p1.first < p2.first;
			return p1.second < p2.second;
		});
	int ch = 0;
	int ans = 0;
	for(int i=0;i<v.size();i++)
	{
		if(ch<=v[i].first)
		{
			ch = v[i].second;
			ans++;
		}
	}
	cout << ans;
	return 0;
}