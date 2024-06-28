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
int n, m, k;
int ans = 2e9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	do
	{
		int cur = 0;
		int work = 0;
		for (int i = 0; i < k; i++)
		{
			int tmp = 0;
			while (1)
			{
				tmp += v[cur];
				if (tmp > m)
					break;
				work += v[cur];
				cur = (cur + 1) % n;
			}
		}
		ans = min(ans, work);

	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
	return 0;
}