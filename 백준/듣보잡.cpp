#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
string hear[500001];
string See[500001];
int main()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> hear[i];
	}
	for (int i = 0; i < K; i++)
	{
		cin >> See[i];
	}

	map<string, int> m;
	if (N > K)
	{
		for (int i = 0; i < N; i++)
		{
			m.insert({ hear[i],0 });
		}
		for (int i = 0; i < N; i++)
		{
			if (m.find(See[i]) != m.end())
				m[See[i]]++;
		}
	}
	else
	{
		for (int i = 0; i < K; i++)
		{
			m.insert({ See[i],0 });
		}

		for (int i = 0; i < N; i++)
		{
			if (m.find(hear[i]) != m.end())
				m[hear[i]]++;
		}

	}

	int count = 0;
	for (auto i : m)
	{
		if (i.second == 1)
		{
			count++;
		}
	}
	cout << count << endl;
	for (auto i : m)
	{
		if (i.second == 1)
		{
			cout << i.first << endl;
		}
	}
	return 0;
}