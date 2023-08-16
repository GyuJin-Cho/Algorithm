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
	int n = 20;
	int m;
	cin >> m;
	int BIT = 0;
	string s;
	int x;
	while (n--)
	{
		cin >> s;
		if (s == "add")
		{
			cin >> x;
			x--;
			BIT = (BIT | (1 << x));
		}
		else if (s == "remove")
		{
			cin >> x;
			x--;
			BIT = (BIT & (~(1 << x)));
		}
		else if (s == "check")
		{
			cin >> x;
			x--;
			if (BIT & (1 << x))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (s == "toggle")
		{
			cin >> x;
			x--;
			BIT = BIT ^ (1 << x);
		}
		else if (s == "all")
		{
			BIT = (1 << n) - 1;
		}
		else if (s == "empty")
		{
			BIT = 0;
		}
	}

	return 0;
}