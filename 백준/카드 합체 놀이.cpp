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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	long long ans = 0;
	while(m--)
	{
		sort(v.begin(), v.end());
		long long sum = v[0] + v[1];
		v[0] = sum;
		v[1] = sum;
	}

	for (int i = 0; i < v.size(); i++)
		ans += v[i];

	cout << ans;

	return 0;
}