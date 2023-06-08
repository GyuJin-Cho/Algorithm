#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;

int main()
{
	int n, k, m=0;
	cin >> n >> k;

	for(int i=1;i<=k;i++)
	{
		m = m + i;
	}
	if (n < m)
	{
		cout << -1;
		return 0;
	}

	n = n - m;
	n = n % k;
	if (n == 0)
		cout << k - 1;
	else
		cout << k;

	return 0;
}