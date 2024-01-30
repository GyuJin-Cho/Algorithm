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
	string n;
	cin >> n;
	sort(n.begin(), n.end(),greater<>());
	if (n[n.size() - 1] != '0')
		cout << -1;
	else
	{
		long long ans = 0;
		for (auto i : n)
			ans += i - 48;
		if (ans % 3 == 0)
			cout << n;
		else
			cout << -1;
	}
	return 0;
}