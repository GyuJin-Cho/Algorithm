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

int main()
{
	int n;
	cin >> n;
	vector<int> boxes(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++)
		cin >> boxes[i];

	int Max = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (boxes[j] < boxes[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		Max = max(Max, dp[i]);
	}
	cout << Max;
	return 0;
}