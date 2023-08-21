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
long long d[1001][10];
const int mod = 10007;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= 9; i++)
	{
		d[1][i] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				d[i][j] += d[i - 1][k];
				d[i][j] %= mod;
			}
		}
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++)
	{
		answer += d[n][i];
	}
	answer %= mod;
	cout << answer;
	return 0;
}