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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for(int i=0;i<m;i++)
	{
		int a, b;
		cin >> a >> b;
		int first = lower_bound(v.begin(), v.end(), a) - v.begin();
		int second = upper_bound(v.begin(), v.end(), b) - v.begin();
		cout << second - first << '\n';
	}
	return 0;
}