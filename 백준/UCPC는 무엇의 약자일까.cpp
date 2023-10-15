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
	string s;
	getline(cin, s);
	string ans = "";
	for(int i=0;i<s.length();i++)
	{
		if (s[i] == 'U' && ans.empty())
			ans += 'U';
		else if (s[i] == 'C' && ans == "U")
			ans += 'C';
		else if (s[i] == 'P' && ans == "UC")
			ans += 'P';
		else if (s[i] == 'C' && ans == "UCP")
			ans += 'C';
	}
	if (ans == "UCPC")
		cout << "I love UCPC";
	else
		cout << "I hate UCPC";

	return 0;
}