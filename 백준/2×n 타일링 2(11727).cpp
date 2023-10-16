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
int dp[1001];
int main()
{
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	
	for(int i=3;i<=n;i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1] + dp[i-2])%10007;
	}
	cout << dp[n];
	return 0;
}