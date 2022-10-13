#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		v.push_back(c);
	}
	int count = 0;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (K / v[i] != 0)
		{
			count += K / v[i];
			K = K - (v[i]*(K / v[i]));
		}
	}
	cout << count;
	return 0;
}