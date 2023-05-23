#include <iostream>

using namespace std;

int main()
{
	int n, m;
	int sum = 0;
	int ans = -21740000;
	for(int i=0;i<4;i++)
	{
		cin >> n >> m;
		sum = sum - n + m;
		ans = max(ans, sum);
	}
	cout << ans;
	return 0;
}