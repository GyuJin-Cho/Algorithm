#include<iostream>

using namespace std;

long long Fac(int N)
{
	if (N == 0 || N == 1)
		return 1;
	else
		return N * Fac(N - 1);
}

int main()
{
	int N;
	cin >> N;
	long long ans = Fac(N);
	cout << ans;
}