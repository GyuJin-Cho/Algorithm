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
	int T;
	cin >> T;
	while (T--)
	{
		int p,n;
		cin >> p;
		vector<int> v;
		int ans = 0;
		for (int i = 0; i < 20; i++)
		{
			cin >> n;
			v.push_back(n);
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = i; j < 20; j++)
			{
				if (v[i] > v[j])
					ans++;
			}
		}
		

		cout << p <<' ' << ans << '\n';
	}
	return 0;
}