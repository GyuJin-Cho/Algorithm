#include<iostream>

using namespace std;

int Chang = 100;
int Sang = 100;

pair<int, int> arr[15];

void solve(const int& n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i].first > arr[i].second)
		{
			Sang -= arr[i].first;
		}
		else if (arr[i].first < arr[i].second)
		{
			Chang -= arr[i].second;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = make_pair(a, b);
	}
	solve(n);

	cout << Chang << '\n' << Sang;

	return 0;
}