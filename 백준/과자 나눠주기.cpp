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
	vector<int> v(m);
	for(int i=0;i<m;i++)
	{
		cin >> v[i];
	}

	int left = 1;
	int right = *max_element(v.begin(), v.end());
	int ans = 0;

	while(left<=right)
	{
		int sum = 0;
		int mid = (left + right) / 2;
		for(int i=0;i<m;i++)
		{
			sum += v[i] / mid;
		}
		if (sum >= n)
		{
			left = mid + 1;
			ans = mid;
		}
		else if (sum < n)
			right = mid - 1;

	}
	cout << ans;
	return 0;
}