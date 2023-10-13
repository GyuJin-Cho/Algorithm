#include<iostream>

using namespace std;

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans += i;
		cout << ans<<'\n';
	}

	return 0;
}