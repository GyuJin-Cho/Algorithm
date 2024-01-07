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
const int INF = 1e9;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, s;
	cin >> n >> s;
	vector<int> v(n + 1);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int start = -1;
	int end = -1;
	int ans = INF;
	int sum = 0;

	while (start <= end && n > end)
	{
		if (sum < s)
		{
			end++;
			sum += v[end];
		}
		else if (sum >= s)
		{
			ans = min(ans, end - start);
			start++;
			sum -= v[start];
		}
	}
	if (ans == INF)
		cout << 0;
	else
		cout << ans;
	return 0;
}