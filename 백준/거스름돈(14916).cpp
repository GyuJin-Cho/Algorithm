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
constexpr int MAX = 100005;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int cost;
	cin >> cost;
	int DP[MAX];
	fill(DP, DP + cost + 1, -1);
	DP[2] = 1;
	DP[4] = 2;
	DP[5] = 1;
	

	for(int i=6;i<=cost;i++)
	{
		if (DP[i - 2] == -1 && DP[i - 5] == -1)
			continue;
		else if (DP[i - 2] == -1)
			DP[i] = DP[i - 5] + 1;
		else if (DP[i - 5] == -1)
			DP[i] = DP[i - 2] + 1;
		else
			DP[i] = min(DP[i - 2] + 1, DP[i - 5] + 1);
	}
	
	cout << DP[cost];
	return 0;
}