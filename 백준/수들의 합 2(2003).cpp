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
	vector<long long> v(n+1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int start = -1;
	int end = -1;
	long long sum = 0;
	int ans = 0;
	while(start<=end&&end<n)
	{
		if(sum>m)
		{
			start++;
			sum -= v[start];
		}
		else if(sum<m)
		{
			end++;
			sum += v[end];
		}
		else if(sum==m)
		{
			end++;
			ans++;
			sum += v[end];
		}
	}
	cout << ans;
	return 0;
}