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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	int sum = 0;
	vector<int> v1;
	for (int i = 0; i < n; i++)
	{
		sum += v[i];
		v1.push_back(sum);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += v1[i];
	}
	cout << ans;
	return 0;
}