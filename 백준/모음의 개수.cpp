#include<iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	int ans = 0;
	while(1)
	{
		ans = 0;
		getline(cin, s);
		if (s == "#")
			break;
		for(int i=0;i<s.size();i++)
		{
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
				ans++;
		}
		cout << ans << '\n';
	}

	return 0;
}