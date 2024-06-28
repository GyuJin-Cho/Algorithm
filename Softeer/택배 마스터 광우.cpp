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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> rail(n, 0);
	for (int i = 0; i < n; i++)
		cin >> rail[i];
	int ans = 1e9;
	do
	{
		int cnt = 0;
		int sum = 0;
		int tmp = 0;
		int idx = 0;
		while (cnt < k)
		{
			tmp = 0;
			while (tmp + rail[idx] <= m)
			{
				tmp += rail[idx];
				sum += rail[idx];
				idx = (idx + 1) % n;
			}
			cnt++;
		}
		ans = min(sum, ans);
	} while (next_permutation(rail.begin(), rail.end()));
	cout << ans;
	return 0;
}