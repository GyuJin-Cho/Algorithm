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

	int n, score, p;
	cin >> n >> score >> p;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	v.push_back(score);
	sort(v.begin(), v.end(), greater<>());

	int rank = 0;
	int idx;
	for (idx = 0; idx < v.size(); idx++)
	{
		rank = idx + 1;
		while (idx + 1 < v.size() && v[idx + 1] == v[idx])
			idx++;
		if (v[idx] == score)
			break;
	}
	if (idx < p)
		cout << rank;
	else
		cout << -1;
	return 0;
}