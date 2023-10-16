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
int n;
int ans = -217400000;
int t[21], p[21];
void DFS(int idx, int sum)
{
	if (idx == n+1)
	{
		ans = max(ans, sum);
		return;
	}
	if (idx > n + 1)
		return;
	DFS(idx +t[idx], sum + p[idx]);
	DFS(idx + 1, sum);
}

int main()
{
	cin >> n;


	for(int i=1;i<=n;i++)
	{
		cin >> t[i] >> p[i];
	}

	DFS(1, 0);
	cout << ans;
	return 0;
}