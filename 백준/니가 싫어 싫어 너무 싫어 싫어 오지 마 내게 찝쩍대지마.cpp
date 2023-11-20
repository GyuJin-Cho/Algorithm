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
	unordered_map<int, int>um;
	vector<pair<int, int>> v;

	for(int i=0;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		if (um.count(a))
			um[a]++;
		else
			um[a] = 1;
		if (um.count(b))
			um[b]--;
		else
			um[b] = -1;
	}
	v.assign(um.begin(), um.end());
	sort(v.begin(), v.end());

	int ans = 0, cur = 0;
	int stt = 0, end = -1;

	for(int i=0;i<v.size();i++)
	{
		cur += v[i].second;
		if(cur>ans)
		{
			ans = cur;
			stt = v[i].first;
			end = -1;
		}
		else if(cur<ans)
		{
			if (end == -1)
				end = v[i].first;
		}
	}

	cout << ans << '\n' << stt << ' '<<end;

	return 0;
}