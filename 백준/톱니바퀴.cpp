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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 4;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int no, dir;
		cin >> no >> dir;
		no -= 1;
		vector<int> d(n);
		d[no] = dir;
		for (int i = no - 1; i >= 0; i--)
		{
			if (a[i][2] != a[i + 1][6])
			{
				d[i] = -d[i + 1];
			}
			else
			{
				break;
			}
		}
		for (int i = no + 1; i < n; i++)
		{
			if (a[i - 1][2] != a[i][6])
			{
				d[i] = -d[i - 1];
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (d[i] == 0)
			{
				continue;
			}
			if (d[i] == 1)
			{
				char temp = a[i][7];
				for (int j = 7; j >= 1; j--)
				{
					a[i][j] = a[i][j - 1];
				}
				a[i][0] = temp;
			}
			else if (d[i] == -1)
			{
				char temp = a[i][0];
				for (int j = 0; j < 7; j++)
				{
					a[i][j] = a[i][j + 1];
				}
				a[i][7] = temp;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == '1')
		{
			ans = ans + (pow(2, i));
		}
	}
	cout << ans;
	return 0;
}