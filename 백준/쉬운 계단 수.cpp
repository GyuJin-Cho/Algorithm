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

using namespace std;
long long D[101][10];
long long mod = 1000000000;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		D[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			D[i][j] = 0;
			if (j - 1 >= 0)
				D[i][j] += D[i-1][j - 1];
			if (j + 1 <= 9)
				D[i][j] += D[i-1][j + 1];
			D[i][j] %= mod;
		}
	}
	long long answer = 0;
	for (int i = 0; i <= 9; i++)
	{
		answer += D[n][i];
	}
	answer %= mod;
	cout << answer;
	return 0;
}