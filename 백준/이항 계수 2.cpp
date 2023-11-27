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
long long DP[1001][1001];
constexpr int MOD = 10007;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	DP[0][0] = 1;
	DP[1][0] = 1;
	DP[1][1] = 1;

	int n, k;
	cin >> n >> k;

	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if (j == 0)
				DP[i][0] = 1;
			else if (j == i)
				DP[i][j] = 1;
			else
				DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j]) % MOD;
		}
	}
	cout << DP[n][k];
	


	return 0;
}