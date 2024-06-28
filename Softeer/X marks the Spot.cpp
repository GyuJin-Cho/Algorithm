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
	string a, b;
	string ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		for (int i = 0; i < a.size(); i++)
		{
			a[i] = toupper(a[i]);
		}

		int idx = a.find("X");
		ans += b[idx];
	}
	for (int i = 0; i < ans.size(); i++)
		ans[i] = toupper(ans[i]);
	cout << ans;

	return 0;
}