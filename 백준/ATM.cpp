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
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int sum = 0;
	vector<int>ans;
	for (const auto& i : v)
	{
		sum += i;
		ans.push_back(sum);
	}
	sum = 0;
	for (const auto& i : ans)
	{
		sum += i;
	}
	cout << sum;
	return 0;
}