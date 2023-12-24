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
int v[1000001];
int d[50001][101];
int n, k;

int DP(int x,int count, int length)
{
	if (x <= 0 || count > k)
		return length;
	if (d[x][count] != 0)
		return d[x][count];

	int value = 0;

	if (v[x] % 2 == 0)
		value = DP(x - 1, count, length + 1);
	else if (count < k)
		value = DP(x - 1, count + 1, length);
	else if (count == k)
		return length;
	return d[x][count] = value;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> v[i];

	int ans = 0;

	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<k;j++)
		{
			if (v[i] % 2 == 0)
				ans = max(ans, DP(i, j, 0));
		}
	}
	cout << ans;
	return 0;
}