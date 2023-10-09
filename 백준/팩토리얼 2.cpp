#include<iostream>

using namespace std;


int main()
{
	int n;
	cin >> n;
	unsigned long long ans = 1;
	for(int i=1;i<=n;i++)
	{
		ans *= i;
	}
	cout << ans;
	return 0;
}