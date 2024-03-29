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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long start = 0;
	long long end = v[n-1];
	long long ans = -21740000;
	
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] - mid > 0)
				sum += (v[i] - mid);
		}
		if (sum > m)
		{
			start = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else if (sum < m)
		{
			end = mid - 1;
		}
		else if (sum == m)
		{
			start = mid + 1;
			if (ans < mid)
				ans = mid;
		}
	}
	cout << ans;
	return 0;
}