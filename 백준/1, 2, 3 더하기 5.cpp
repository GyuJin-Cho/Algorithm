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
long long D[1000001][4];
const int limit = 100000;
const long long mod = 1000000009;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 1; i <= limit; i++)
	{
		if (i - 1 >= 0)
		{
			D[i][1] = D[i - 1][2] + D[i - 1][3];
			if (i == 1)
			{
				D[i][1] = 1;
			}
		}
		if (i - 2 >= 0)
		{
			D[i][2] = D[i - 2][1] + D[i - 2][3];
			if (i == 2)
			{
				D[i][2] = 1;
			}
		}
		if (i - 3 >= 0)
		{
			D[i][3] = D[i - 3][1] + D[i - 3][2];
			if (i == 3)
			{
				D[i][3] = 1;
			}
		}
		D[i][1] %= mod;
		D[i][2] %= mod;
		D[i][3] %= mod;
	}
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		cout << (D[n][1] + D[n][2] + D[n][3])%mod<<'\n';
	}
	return 0;

}