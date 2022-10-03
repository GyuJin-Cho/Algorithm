#include<iostream>

using namespace std;

long long Calculation(long long a, long long b)
{
	return (a + b) * (a - b);
}

int main()
{
	long long a, b;
	cin >> a >> b;
	cout << Calculation(a, b);

	return 0;
}