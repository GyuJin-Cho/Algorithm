#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	unsigned long long n;
	cin >> n;
	unsigned long long ans = sqrt(n);
	if (ans * ans < n)
		ans++;
	cout << ans;

	return 0;
}