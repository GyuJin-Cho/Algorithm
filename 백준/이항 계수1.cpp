#include<iostream>

using namespace std;

int Fac(int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 1;
	else
		return n * Fac(n - 1);
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Fac(n) / (Fac(k) * Fac(n - k));
	return 0;
}