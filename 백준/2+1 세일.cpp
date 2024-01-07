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
	vector<int> items(n);
	for (int i = 0; i < n; i++)
		cin >> items[i];
	sort(items.begin(), items.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if ((i + 1) % 3 == 0)
			continue;
		else
			ans += items[i];
	}
	cout << ans;
	return 0;
}