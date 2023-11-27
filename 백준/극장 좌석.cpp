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
int DP[41];
int main()
{
	int n,m;
	cin >> n>>m;
	int VIP;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	for(int i=3;i<=40;i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}
	int idx = 1;
	int ans = 1;
	while(m--)
	{
		cin >> VIP;
		ans *= DP[VIP - idx];
		idx = VIP + 1;
	}
	ans *= DP[n + 1 - idx];
	cout << ans;
	return 0;
}