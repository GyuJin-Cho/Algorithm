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
	long long n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	long long s = 0;
	long long e = 0;
	long long ans = 1e11;
	sort(v.begin(), v.end());
	while(e<v.size()&&s<=e)
	{
		long long num1 = v[s];
		long long num2 = v[e];
		long long diff = abs(num1 - num2);
		if(diff >=m)
		{
			ans = min(ans, diff);
			s++;
		}
		else if(diff<m)
		{
			e++;
		}
	}
	if (ans == 1e11)
		ans = 0;
	cout << ans;
	return 0;
}