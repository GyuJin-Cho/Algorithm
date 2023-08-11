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
	int t;
	cin >> t;
	while (t--)
	{
		bool flag = false;
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--;
		y--;
		for (int k = x; k < (m * n); k += m)
		{
			if (k % n == y)
			{
				flag = true;
				cout << k + 1 << '\n';
				break;
			}
		}
		if (!flag)
			cout << -1 << '\n';
	}

	return 0;
}