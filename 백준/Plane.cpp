#include<iostream>

using namespace std;

int main()
{
	int n1, k1, n2, k2;
	cin >> n1 >> k1 >> n2 >> k2;

	int k = k1 * n1;
	int n = k2 * n2;
	cout << k + n;

	return 0;
}