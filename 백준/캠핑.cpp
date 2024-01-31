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
	int testcase = 1;
	while (1)
	{
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0)
			break;
		int ch = v % p > l ? l : v % p;
		int ans = (v / p) * l + ch;
		cout << "Case " << testcase << ": " << ans << '\n';
		testcase++;
	}

	return 0;
}