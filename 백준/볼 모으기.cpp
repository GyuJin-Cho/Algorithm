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

int n, cnt, ans = 1e9;
string s;

void Group(char x)
{
	cnt = 0;
	bool ch = false;
	for(int i=0;i<s.size();i++)
	{
		if (s[i] != x)
			ch = true;
		else if (ch && s[i] == x)
			cnt++;
	}
	ans = min(ans, cnt);
	ch = false;
	cnt = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if (s[i] != x)
			ch = true;
		else if (ch && s[i] == x)
			cnt++;
	}
	ans = min(ans, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> s;

	Group('R');
	Group('B');
	cout << ans;
	return 0;
}