#include<iostream>
#include<cmath>
using namespace std;

int gcd(int n, int b)
{
	if (b == 0)
		return n;
	else
	{
		return gcd(b, n % b);
	}
}

int main()
{
	int max;
	int min;

	int a, b;
	
	cin >> a >> b;
	max=gcd(a, b);
	cout << max<<endl;
	min = (a * b) / max;
	cout << min;
	return 0;
}