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
#define MAX 100001
int dist[MAX];
int cost[MAX];
int main()
{
	int n;
	long long ans = 0;
	long long now;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		cin >> dist[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}

	now = cost[0];
	ans = now * dist[1];

	for (int i = 1; i < n; i++)
	{
		if (now < cost[i])
		{
			ans += now * dist[i + 1];
		}
		else
		{
			now = cost[i];
			ans += now * dist[i + 1];
		}
	}
	cout << ans;

	return 0;
}