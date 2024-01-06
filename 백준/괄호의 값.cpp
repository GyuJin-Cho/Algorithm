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
	string str;
	cin >> str;
	stack<char> s;

	int ans = 0, temp = 1;

	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			temp *= 2;
			s.push('(');
		}
		else if(str[i]=='[')
		{
			temp *= 3;
			s.push('[');
		}
		else if(str[i]==')')
		{
			if(s.empty()||s.top()!='(')
			{
				ans = 0;
				break;
			}
			if(str[i-1]=='(')
			{
				ans += temp;
				temp /= 2;
				s.pop();
			}
			else
			{
				temp /= 2;
				s.pop();
			}
		}
		else if(str[i]==']')
		{
			if(s.empty()||s.top()!='[')
			{
				ans = 0;
				break;
			}
			if(str[i-1]=='[')
			{
				ans += temp;
				temp /= 3;
				s.pop();
			}
			else
			{
				temp /= 3;
				s.pop();
			}
		}
	}
	if (!s.empty())
		ans = 0;
	cout << ans;
	return 0;
}