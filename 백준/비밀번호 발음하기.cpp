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
char checkword[] = { 'a','e','i','o','u' };
bool Check1(const string& s)
{
	for(int i=0;i<5;i++)
	{
		if(s.find(checkword[i])!=string::npos)
		{
			return true;
		}
	}
	return false;
}

bool Check2(const string& s)
{
	int cn1 = 0;
	int cn2 = 0;
	for(int i=0;i<s.length();i++)
	{
		bool checking = false;
		for(int j=0;j<5;j++)
		{
			if(s[i]==checkword[j])
			{
				cn1++;
				cn2 = 0;
				checking = true;
				break;
			}
		}
		if(!checking)
		{
			cn2++;
			cn1 = 0;
		}
		if (cn1 == 3 || cn2 == 3)
			return false;
	}
	return true;
}

bool Check3(const string& s)
{
	string tmp;
	tmp += s[0];
	for(int i=1;i<s.length();i++)
	{
		if(tmp[tmp.length()-1]==s[i])
		{
			if(tmp[tmp.length()-1]!='e'&& tmp[tmp.length() - 1] != 'o')
			{
				return false;
			}
		}
		else
		{
			tmp.clear();
			tmp += s[i];
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	while(cin>>s)
	{
		if (s == "end")
			break;
		if(!Check1(s)||!Check2(s)||!Check3(s))
		{
			cout << "<" << s << "> " << "is not acceptable." << '\n';
		}
		else
		{
			cout << "<" << s << "> " << "is acceptable." << '\n';
		}

	}

	return 0;
}