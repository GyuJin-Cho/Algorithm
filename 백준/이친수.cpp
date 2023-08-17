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
long long D[91][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	D[1][0] = 0;
	D[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		D[i][0] = D[i - 1][0] + D[i - 1][1];
		D[i][1] = D[i-1][0];
	}
	
	long long ans = 0;
	for (int i = 0; i < 2; i++)
	{
		ans += D[n][i];
	}
	cout << ans;
	return 0;
}