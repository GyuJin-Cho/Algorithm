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
long long d[100001][3];
const int mod = 9901;
int main()
{
	int n;
	cin >> n;
	d[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
		d[i][1] = d[i - 1][0] + d[i - 1][2];
		d[i][2] = d[i - 1][0] + d[i - 1][1];
		for (int j = 0; j < 3; j++)
		{
			d[i][j] %= mod;
		}
	}
	int ans = d[n][0] + d[n][1] + d[n][2];
	ans %= mod;
	cout << ans;
	return 0;
}