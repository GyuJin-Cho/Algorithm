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
vector<pair<int, int>> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({ a,1 });
		arr.push_back({ b,-1 });
	}

	sort(arr.begin(), arr.end());
	int ans = 0;
	int cnt = 0;
	for(int i=0;i<arr.size();i++)
	{
		cnt += arr[i].second;
		ans = max(ans, cnt);
	}
	
	cout << ans;
	return 0;
}