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
int d[61][61][61];
int DP(int i, int j, int k)
{
	if (i < 0)
		return DP(0, j, k);
	if (j < 0)
		return DP(i, 0, k);
	if (k < 0)
		return DP(i, j, 0);
	if (i == 0 && j == 0 && k == 0)
		return 0;
	int answer = d[i][j][k];
	if (answer != -1)
		return answer;
	answer = 10000000;
	vector<int> p = { 1,3,9 };
	do
	{
		if (answer > DP(i - p[0], j - p[1], k - p[2]))
			answer = DP(i - p[0], j - p[1], k - p[2]);
	} while (next_permutation(p.begin(), p.end()));
	answer += 1;
	return answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int scv[3] = { 0,0,0 };
	for (int i = 0; i < n; i++)
		cin >> scv[i];
	memset(d, -1, sizeof(d));
	cout << DP(scv[0], scv[1], scv[2]);
	return 0;
}