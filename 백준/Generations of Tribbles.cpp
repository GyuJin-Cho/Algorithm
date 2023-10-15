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

unsigned long long dp[70];

int main()
{
	int t,n;
	cin >> t;
	
	while(t--)
	{
		cin >> n;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for(int i=4;i<=n;i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
		cout << dp[n]<<'\n';
	}

	return 0;
}