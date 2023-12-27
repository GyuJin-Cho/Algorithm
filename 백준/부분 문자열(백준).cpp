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
	string s, t;
	while(cin>>s>>t)
	{
		int idx = 0;
		bool ch = false;
		for(int i=0;i<t.length();i++)
		{
			if (s[idx] == t[i])
				idx++;
			if (idx == s.length())
			{
				ch = true;
				break;
			}
		}
		if (ch)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}