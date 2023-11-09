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
int n;
vector<pair<int, int>> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,b });
	}
	sort(arr.begin(), arr.end());
	int start = arr[0].first;
	int end = arr[0].second;
	int ans = 0;
	for(int i=1;i<n;i++)
	{
		int s = arr[i].first;
		int e = arr[i].second;
		if(end>=s)
		{
			if(end<e)
			{
				end = e;
			}
		}
		else
		{
			ans += end - start;
			start = s;
			end = e;
		}
	}
	ans += end - start;
	cout << ans;
	return 0;
}