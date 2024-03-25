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
#include<cstring>

using namespace std;
char arr[1501][1501];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	int li, lj, ui, uj;
	li = lj = n;
	ui = uj = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'G')
			{
				if (li > i)
					li = i;
				if (ui < i)
					ui = i;
				if (lj > j)
					lj = j;
				if (uj < j)
					uj = j;
			}
		}
	}
	int ans = 0;
	if (li != ui)
		ans += min(ui, n - 1 - li);
	if (lj != uj)
		ans += min(uj, n - 1 - lj);
	cout << ans;

	return 0;
}