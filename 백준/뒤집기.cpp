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
	cin >> s;
	int ans = 0;

	for(int i=0;i<s.length();i++)
	{
		if (s[i] != s[i + 1])
			ans++;
	}

	if (!ans)
		cout << ans;
	else
		cout << ans / 2;

	return 0;
}