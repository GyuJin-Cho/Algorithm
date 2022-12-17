#include<iostream>
#include <vector>
using namespace std;
long long sum(std::vector<int>& a)
{
	long long Ans = 0;

	for (auto i : a)
	{
		Ans += i;
	}
	return Ans;
}
int main()
{
	int N;
	cin >> N;
	vector<int> V;
	for(int i=0;i<N;i++)
	{
		int t;
		cin >> t;
		V.push_back(t);
	}

	cout << sum(V);

	return 0;
}

