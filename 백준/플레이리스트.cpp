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
int n, m, p;
long long mod = 1000000007;
long long d[101][101];
long long GO(int position, int x)
{
	int y = n - x;
	if(position==p)
	{
		if (y == 0)
			return 1;
		else
			return 0;
	}
	long long& ans = d[position][x];
	if (ans != -1)
		return ans;
	ans = 0;
	if(y>0)
	{
		ans += GO(position + 1, x + 1) * y;
	}
	if(x>m)
	{
		ans += GO(position + 1, x) * (x - m);
	}

	ans %= mod;
	return ans;
}
int main()
{
	
	cin >> n >> m >> p;
	memset(d, -1, sizeof(d));
	cout << GO(0, 0);
	return 0;
}