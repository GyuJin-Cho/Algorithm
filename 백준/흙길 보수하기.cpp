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
vector<pair<int,int>> arr;
int n, l;
int answer;
void Sweeping()
{
	sort(arr.begin(), arr.end());

	int x = 0;
	for(auto &w : arr)
	{
		if(x>=w.second)
			continue;
		x = max(x, w.first);
		int cnt = (w.second - (x + 1)) / l + 1;
		answer += cnt;
		x += l * cnt;
	}
}

int main()
{
	cin >> n >> l;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr.push_back({a, b});
	}
	Sweeping();
	cout << answer;
	return 0;
}