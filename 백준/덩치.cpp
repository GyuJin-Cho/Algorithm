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
#include<tuple>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<tuple<int, int, int>>v;
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back(make_tuple(a, b, 1));
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j)
				continue;
			if (get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j]))
				get<2>(v[i])++;
		}
	}
	for (const auto& i : v)
	{
		cout << get<2>(i) << ' ';
	}
	return 0;
}