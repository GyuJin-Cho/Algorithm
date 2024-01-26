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
long long arr[101][101];
long long dp[101][101];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N;j++)
			cin >> arr[i][j];

	dp[0][0] = 1;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			long long jmp = arr[i][j];
			if (i != N - 1 && i + jmp < N)
				dp[i + jmp][j] += dp[i][j];
			if (j != N - 1 && j + jmp < N)
				dp[i][j + jmp] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];
	return 0;
}