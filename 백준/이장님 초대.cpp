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

int solution(vector<int>& v)
{
	sort(v.begin(), v.end(), greater<>());
	int ans = -1e9;
	for (int i = 0; i < n; i++)
		ans = max(ans, v[i] + i + 1);
	ans++;
	return ans;
}

int main()
{
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << solution(v);

	return 0;
}