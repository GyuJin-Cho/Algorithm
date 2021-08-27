#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int>& v1, pair<int, int>& v2)
{
	if (v1.first < v2.first)
		return true;
	else if (v1.first == v2.first)
	{
		if (v1.second < v2.second)
			return true;
		else
			return false;
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	vector<pair<int, int>> v(T);

	int x, y;
	for (int i = 0; i < T; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < T; i++)
	{
		cout << v[i].first << " " << v[i].second<<'\n';
	}
	return 0;
}