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
long long d[201][201];
const int mod = 1000000000;
int main()
{
	d[0][0] = 1;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}

	cout << d[k][n] % mod;

	return 0;
}