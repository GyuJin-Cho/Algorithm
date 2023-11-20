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
vector<pair<int, int>>v;
constexpr int MAX = (1000 * 100) + 1;
int dp[MAX];
int main()
{
	int c, m;
	cin >> c >> m;
	for(int i=1;i<=m;i++)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });

	}
	for(int i=0;i<v.size();i++)
	{
		for(int j=1;j<=MAX;j++)
		{
			if(j-v[i].first>=0)
			{
				dp[j] = max(dp[j], dp[j - v[i].first] + v[i].second);
			}
		}
	}

	for(int i=1;i<MAX;i++)
	{
		if(dp[i]>=c)
		{
			cout << i;
			break;
		}
	}

	return 0;
}