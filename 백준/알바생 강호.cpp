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
	sort(v.begin(), v.end(),greater<>());
	long long ans = 0;
	for(int i=0;i<n;i++)
	{
		int tmp = v[i] - ((i + 1) - 1);
		if(tmp<0)
			continue;
		ans += tmp;
	}
	cout << ans;

	return 0;
}