#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<tuple<int, int , int>> v;
	for (int i = 0; i < N; i++)
	{
		int a;
		int b;
		cin >> a >> b;
		v.push_back(make_tuple(a,b,1));
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			if (get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j]))
			{
				get<2>(v[i])++;
			}
		}
	}

	for (int i = v.size()-1; i >= 0; i--)
	{
		for (int j = i - 1; j >=0; j--)
		{
			if (get<0>(v[i]) < get<0>(v[j]) && get<1>(v[i]) < get<1>(v[j]))
			{
				get<2>(v[i])++;
			}
		}
	}

	for (auto i : v)
	{
		cout << get<2>(i) << endl;;
	}

	return 0;
}