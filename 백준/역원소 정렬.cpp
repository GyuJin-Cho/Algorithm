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
	vector<string>v(n);
	vector<long long> ans;

	for(int i=0;i<n;i++)
	{
		cin >> v[i];
		reverse(v[i].begin(), v[i].end());
		ans.push_back(stoll(v[i]));
	}

	sort(ans.begin(), ans.end());

	for(long long& i : ans)
	{
		cout << i << '\n';
	}
	return 0;
}