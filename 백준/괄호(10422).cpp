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

long long d[5001];
const long long mod = 1000000007;

long long DP(int n)
{
	if (n == 0)
		return 1;
	else if (d[n] >= 0)
		return d[n];
	d[n] = 0;
	for(int i=2;i<=n;i+=2)
	{
		d[n] += DP(i - 2) * DP(n - i);
		d[n] %= mod;
	}
	return d[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	memset(d, -1, sizeof(d));
	while(t--)
	{
		int n;
		cin >> n;
		if (n % 2 == 0)
			cout << DP(n) << '\n';
		else
			cout << 0 << '\n';
	}
	return 0;
}