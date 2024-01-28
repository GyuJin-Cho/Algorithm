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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 0;
	int val;
	for (int i = 0; i < n; i++)
	{
		val = v[i];
		int l = 0, r = n - 1, sum;
		while (l < r)
		{
			sum = v[l] + v[r];
			if (sum == val)
			{
				if (l != i && r != i)
				{
					ans++;
					break;
				}
				else if (l == i)
					l++;
				else if (r == i)
					r--;
			}
			else if (sum < val)
				l++;
			else
				r--;
		}
	}
	cout << ans;
	return 0;
}