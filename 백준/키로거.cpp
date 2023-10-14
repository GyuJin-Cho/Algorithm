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
#include<list>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	list<char> password;
	list<char>::iterator cur;
	string s;
	for(int j=0;j<T;j++)
	{
		cin >> s;
		password.clear();
		cur = password.begin();
		
		for(int i=0;i<s.length();i++)
		{
			if (s[i] == '<')
			{
				if (cur != password.begin())
					cur--;
			}
			else if(s[i] =='>')
			{
				if (cur != password.end())
					cur++;
			}
			else if (s[i] == '-')
			{
				if (cur != password.begin())
					cur = password.erase(--cur);
			}
			else
			{
				password.insert(cur, s[i]);
			}
				
		}
		for (auto z : password)
			cout << z;
		cout << '\n';
	}
	return 0;
}