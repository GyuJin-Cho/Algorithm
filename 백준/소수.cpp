#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

bool IsPrime(int n)
{
	if (n <= 1)
		return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int sum = 0;
	int M, N;
	cin >> M >> N;
	int minimum=INT_MAX;
	for(int i=M;i<=N;i++)
	{
		if(IsPrime(i))
		{
			sum += i;
			minimum = min(minimum, i);
		}
	}

	if (sum == 0)
		cout << -1;
	else
		cout << sum << '\n' << minimum;

	return 0;
}