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

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	bool flag = false;
	bool check = false;
	do
	{
		if (!flag)
		{
			flag = true;
			continue;
		}
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i]<<' ';
		}
		check = true;
		break;
	} while (next_permutation(v.begin(), v.end()));
	if (!check)
		cout << -1;

	return 0;
}