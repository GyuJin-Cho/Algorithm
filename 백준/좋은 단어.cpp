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
	int n;
	cin >> n;
	string s;
	int ans = 0;
	while(n--)
	{
		cin >> s;
		stack<char> st;
		for(int i=0;i<s.length();i++)
		{
			if (st.empty())
				st.push(s[i]);
			else
			{
				if (st.top() == s[i])
					st.pop();
				else
					st.push(s[i]);
			}
		}
		if (st.empty())
			ans++;
	}
	cout << ans;
	return 0;
}