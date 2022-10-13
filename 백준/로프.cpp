#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int Max = -1;
	for (int i = 0; i < N; i++)
	{
		Max = max(Max, v[i] * (N - i));
	}
	cout << Max;
	return 0;
}