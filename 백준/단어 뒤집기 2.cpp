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
	getline(cin, s);

	string answer = "";
	string tmp = "";
	bool flag = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ' && !flag)
		{
			reverse(tmp.begin(), tmp.end());
			answer += tmp;
			answer += ' ';
			tmp.clear();
		}
		else if (s[i] == ' ' && !flag)
		{
			tmp += s[i];
		}
		else if (s[i] == '<')
		{
			if (!tmp.empty())
			{
				reverse(tmp.begin(), tmp.end());
				answer += tmp;
				tmp.clear();
			}
			tmp += s[i];
			flag = true;
		}
		else if (s[i] == '>')
		{
			flag = false;
			tmp += s[i];
			answer += tmp;
			tmp.clear();
		}
		else
		{
			tmp += s[i];
		}
	}
	if (!tmp.empty())
	{
		reverse(tmp.begin(), tmp.end());
		answer += tmp;
	}
	cout << answer;
	return 0;
}