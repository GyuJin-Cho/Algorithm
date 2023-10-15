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
	string s, t;
	cin >> s >> t;
	int ans = 0;
	while(1)
	{
		if(s.length()==t.length())
		{
			if(s==t)
			{
				ans = 1;
			}
			break;

		}
		if(t[t.length()-1]=='A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}
	
	cout << ans;
	return 0;
}