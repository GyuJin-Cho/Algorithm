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
constexpr int N = 26;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	vector<int> v1(N);
	vector<int> v2(N);
	string s1, s2;
	int ans = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
		v1[s1[i] - 'a']++;

	for (int i = 0; i < s2.size(); i++)
		v2[s2[i] - 'a']++;

	for (int i = 0; i < N; i++)
		ans += abs(v1[i] - v2[i]);

	cout << ans;
	return 0;
}