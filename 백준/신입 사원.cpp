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
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		
		for(int i=0;i<n;i++)
		{
			int s,e;
			cin >> s >> e;
			v.push_back({ s,e });
		}
		sort(v.begin(), v.end());
		int tmp = 0;
		int ans = 1;
		for(int i=1;i<n;i++)
		{
			if(v[tmp].second>v[i].second)
			{
				ans++;
				tmp = i;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}