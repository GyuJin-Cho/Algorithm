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
	int n, d, k, c;
	cin >> n >> d >> k >> c;
	vector<int> arr(n);
	vector<bool> check(30001, false);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = -1e9;
	for(int i=0;i<n;i++)
	{
		int flag = 0;
		int coupon = 1;
		for(int j=i;j<i+k;j++)
		{
			if (!check[arr[j % n]])
				check[arr[j % n]] = true;
			else
				flag++;
		}
		if (check[c])
			coupon = 0;
		ans = max(ans, k - flag + coupon);
		check.clear();
		check.resize(30001, false);
	}
	cout << ans;
	return 0;
}