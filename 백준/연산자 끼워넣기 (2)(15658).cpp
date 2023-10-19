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

pair<int,int> Caclu(const vector<int> &v, int idx, int cur, int plus, int minus, int mul, int div)
{
	int n = v.size();
	if (idx == n)
		return make_pair(cur, cur);
	vector<pair<int, int>> res;
	if (plus > 0)
		res.push_back(Caclu(v, idx + 1, cur + v[idx], plus - 1, minus, mul, div));
	if (minus > 0)
		res.push_back(Caclu(v, idx + 1, cur - v[idx], plus, minus - 1, mul, div));
	if (mul > 0)
		res.push_back(Caclu(v, idx + 1, cur * v[idx], plus, minus, mul - 1, div));
	if (div > 0)
		res.push_back(Caclu(v, idx + 1, cur / v[idx], plus, minus, mul, div - 1));

	pair<int, int> ans = res[0];
	for(auto p : res)
	{
		if (ans.first < p.first)
			ans.first = p.first;
		if (ans.second > p.second)
			ans.second = p.second;
	}

	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int d[4];

	for (int i = 0; i < 4; i++)
		cin >> d[i];

	pair<int,int> ans = Caclu( v, 1, v[0], d[0], d[1], d[2], d[3]);
	cout << ans.first << '\n' << ans.second;
	return 0;
}