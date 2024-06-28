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
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int a, b;
	vector<bool> best(n,true);
	for (int j = 0; j < m; j++)
	{
		cin >> a >> b;
		if (arr[a - 1] < arr[b - 1])
		{
			best[a - 1] = false;
		}
		else if (arr[a - 1] > arr[b - 1])
		{
			best[b - 1] = false;
		}
		else
		{
			best[a - 1] = false;
			best[b - 1] = false;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (best[i])
			ans++;
	cout << ans;
	return 0;
}
