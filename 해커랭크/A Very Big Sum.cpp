#include<iostream>
using namespace std;


int main()
{
	unsigned long long sum = 0;
	int n;
	cin >> n;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		sum += c;
	}
	cout << sum;
	return 0;
}