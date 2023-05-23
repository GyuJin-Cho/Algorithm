#include<iostream>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	unordered_map<char, int>um;
	um['A'] = 10;
	um['B'] = 11;
	um['C'] = 12;
	um['D'] = 13;
	um['E'] = 14;
	um['F'] = 15;
	int cnt = 0;
	for(int i=s.size()-1;i>=0;i--)
	{
		if(s[i]>='A'&&s[i]<='F')
		{
			ans = ans + ((um[s[i]]) * pow(16, cnt));
		}
		else
		{
			ans = ans + ((s[i] - 48)*pow(16, cnt));
		}
		cnt++;
	}
	cout << ans;
	return 0;
}