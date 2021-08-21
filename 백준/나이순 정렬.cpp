#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool com(pair<int, string> v1,  pair<int, string> v2)
{
	return v1.first < v2.first;
}

int main()
{

	int T;
	cin >> T;
	vector<pair<int, string>> v(T);

	for (int i = 0; i < T; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), com);
	for (int i = 0; i < T; i++)
	{
		cout << v[i].first << " " << v[i].second << '\n';
	}
	return 0;
}