#include<iostream>

using namespace std;

int main()
{
	int sum = 0;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a;
		cin >> a;
		sum += a;
	}
	cout << sum;
	return 0;
}