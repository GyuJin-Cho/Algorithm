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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, m ,num;
	unordered_map<int,int> s;
	while(1)
	{
		s.clear();
		int ans = 0;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			s[num] = 1;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> num;
			if (s[num]==1)
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}