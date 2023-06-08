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
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k, c;
	cin >> k;
	cin >> c;
	int n, m;
	while(c--)
	{
		cin >> m >> n;
		int remaingame = k - max(m, n);
		int diff = abs(m - n);
		if (n == m)
		{
			cout << 1 << '\n';
		}
		else if (m > n)
		{
			if (diff - remaingame <= 2)
			{
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
		else
		{
			if (diff - remaingame <= 1)
			{
				cout << 1 << '\n';
			}
			else
				cout << 0 << '\n';
		}
	}
}