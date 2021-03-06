#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v)
	{
		printf("%d %d\n", i.first, i.second);
	}

	return 0;
}