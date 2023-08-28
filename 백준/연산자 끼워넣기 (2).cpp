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

pair<int, int> DFS(const vector<int>& a, int index, int cur, int plus, int minus, int mul, int div)
{

	int n = a.size();
	if (index == n)
		return make_pair(cur, cur);
	vector<pair<int, int>>res;
	if (plus > 0)
		res.push_back(DFS(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	if (minus > 0)
		res.push_back(DFS(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	if (mul > 0)
		res.push_back(DFS(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
	if (div > 0)
		res.push_back(DFS(a, index + 1, cur / a[index], plus, minus, mul, div - 1));
	pair<int, int> answer = res[0];
	for (auto p : res)
	{
		if (answer.first < p.first)
			answer.first = p.first;
		if (answer.second > p.second)
			answer.second = p.second;
	}
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	pair<int, int> p = DFS(a, 1, a[0], plus, minus, mul, div);
	cout << p.first << '\n';
	cout << p.second;
	return 0;
}