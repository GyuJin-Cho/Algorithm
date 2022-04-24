#include<iostream>
#include<stack>

using namespace std;

int solution(string s)
{
	stack<char> sta;


	for (int i = 0; i < s.length(); i++)
	{
		if (sta.empty() || sta.top() != s[i])
			sta.push(s[i]);
		else if (sta.top() == s[i])
		{
			sta.pop();
		}
	}
	if (sta.empty())
		return 1;
	else
		return 0;
}

int main()
{
	cout << solution("daa");

	return 0;
}