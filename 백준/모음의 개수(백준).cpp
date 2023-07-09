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

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='a' || s[i]=='e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}