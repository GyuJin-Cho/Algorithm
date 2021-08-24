#include<iostream>

using namespace std;

bool sosu(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
int main()
{
	int T;
	cin >> T;
	int a;
	int count = 0;
	for (int i = 0; i < T; i++)
	{
		cin >> a;
		if (sosu(a))
		{
			count++;
		}
	}
	cout << count;
	return 0;
}