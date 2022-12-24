#include<iostream>

using namespace std;

long long cnt;

long long fib(long long n)
{

	if (n == 1 || n == 2)
	{
		cnt++;
		return 1;
	}
	else
		return fib(n - 1) + fib(n - 2);
}

long long fibonacci(long long n)
{
	int fibo[50];
	fibo[1] = fibo[2] = 1;
	for(int i=3;i<=n;i++)
	{
		fibo[i] = fibo[i - 1] + fibo[i - 2];
		cnt++;
	}
	return fibo[n];
}

int main()
{
	int n;
	cin >> n;
	fib(n);
	cout << cnt << " ";
	cnt = 0;
	fibonacci(n);
	cout << cnt;
}