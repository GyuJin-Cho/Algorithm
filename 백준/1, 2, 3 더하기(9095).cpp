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
int dp[12];
int main()
{
	int T;
	cin >> T;
	int num;
	dp[0] = 1;
	for(int i=1;i<11;i++)
	{
		if (i - 1 >= 0)
			dp[i] += dp[i - 1];
		if (i - 2 >= 0)
			dp[i] += dp[i - 2];
		if (i - 3 >= 0)
			dp[i] += dp[i - 3];
	}

	while(T--)
	{
		cin >> num;
		cout << dp[num]<<'\n';
	}

	return 0;
}