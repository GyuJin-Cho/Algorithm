#include<iostream>
using namespace std;

int main()
{
	int a[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	int minval = a[0];
	int maxval = a[0];
	long long sum = a[0];
	for (int i = 1; i < 5; i++)
	{
		minval = min(minval, a[i]);
		maxval = max(maxval, a[i]);
		sum += a[i];
	}
	cout << sum - maxval << " " << sum-minval;
	return 0;
}