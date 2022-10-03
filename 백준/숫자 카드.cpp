#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	unordered_map<long long, int> um;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		um[a] = 1;
	}
	int M;
	cin >> M;
	vector<long long> v;
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (um[v[i]] == 1)
		{
			cout << 1 << " ";
		}
		else
			cout << 0 << " ";
	}
	
}