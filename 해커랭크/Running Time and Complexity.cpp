#include<iostream>

using namespace std;

bool sosu(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int T ,n;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		if (sosu(n))
			cout << "Prime" << endl;
		else
			cout << "Not prime" << endl;
	}
	return 0;
}