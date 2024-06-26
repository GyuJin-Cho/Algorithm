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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr.begin(), arr.end());

	int ans = 0;

	for (int k = 0; k < n; k++)
	{
		int find = arr[k];
		int l = 0;
		int r = n - 1;

		while (l < r)
		{
			if (arr[l] + arr[r] == find)
			{
				if (l != k && r != k)
				{
					ans++;
					break;
				}
				else if (l == k)
					l++;
				else
					r--;
			}
			else if (arr[l] + arr[r] < find)
				l++;
			else
				r--;
		}
	}
	cout << ans;
	return 0;
}