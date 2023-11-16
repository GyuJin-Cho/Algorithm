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
constexpr int MAX = 1500000;
int n;
pair<int, int> input[MAX];
int dp[MAX + 1];
int ans;
int curMAX;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> input[i].first >> input[i].second;

	for(int i=0;i<=n;i++)
	{
		curMAX = max(curMAX, dp[i]);
		if(i+input[i].first>n)
			continue;
		dp[i + input[i].first] = max(dp[i + input[i].first], curMAX + input[i].second);
		ans = max(ans, dp[i + input[i].first]);
	}
	cout << ans;
	return 0;
}