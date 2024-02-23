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
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int ans = 0;
	int Max = 0;
	
	for (int i = 0; i < v.size() - 1; i++)
	{
		int ch = (v[i] + v[i + 1]) / 2;
		if (ch != v[i])
		{
			if (min(ch - v[i], v[i + 1] - ch) > Max)
			{
				ans = ch;
				Max = min(ch - v[i], v[i + 1] - ch);
			}
		}
	}

	if (ans == 0)
		cout << -1;
	else
		cout << ans;

	return 0;
}