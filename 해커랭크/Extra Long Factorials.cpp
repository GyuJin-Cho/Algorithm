#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void multiply(int x, vector<int>& v, int& size)
{
	int carry=0;
	for (int i = 0; i < size; i++)
	{
		int multipl = v[i] * x + carry;
		v[i] = multipl % 10;
		carry = multipl / 10;
	}

	while (carry)
	{
		v[size] = carry % 10;
		carry /= 10;
		size++;
	}
}

void Fac(int n)
{
	vector<int> v(500);

	v[0] = 1;
	int size = 1;
	for (int i = 2; i <= n; i++)
	{
		multiply(i, v, size);
	}
	for (int i = size - 1; i >= 0; i--)
		cout << v[i];
}

int main()
{
	int n;
	cin >> n;
	Fac(n);
	return 0;
}