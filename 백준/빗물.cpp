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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	int n, m, k;
	int x, y;
	int ans = 0;
	cin >> n >> m;
	vector<int> v(m);

	for (int i = 0; i < m; i++)
		cin >> v[i];

	for (int i = 1; i < m; i++)
	{
		int l = 0;
		int r = 0;
		for (int j = 0; j < i; j++)
			l = max(l, v[j]);
		for (int j = m - 1; j > i; j--)
			r = max(r, v[j]);
		ans += max(0, min(l, r) - v[i]);
	}
	cout << ans;
	return 0;
}