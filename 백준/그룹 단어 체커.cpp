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
	string s;
	int ans = 0;
	while (T--)
	{
		cin >> s;
		map<char, int> m;
		bool ch = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (m[s[i]] == 0)
				m[s[i]]++;
			else
			{
				if (s[i - 1] == s[i])
				{
					continue;
				}
				else
				{
					ch = false;
					break;
				}
			}
		}
		if (ch)
			ans++;
	}
	cout << ans;
	return 0;
}