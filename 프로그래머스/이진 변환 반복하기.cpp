#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int ans1;
int ans2;

string step1(string &s)
{
	if (s == "1")
		return "1";
	ans1++;
	string tmp = "";
	for(int i=0;i<s.length();i++)
	{
		if (s[i] == '1')
		{
			tmp += s[i];
		}
		else
			ans2++;
	}
	return tmp;
}

string step2(string &s)
{
	if (s == "1")
		return "1";
	string tmp = "";
	stack<int> st;
	int length = s.length();
	while(length!=0)
	{
		st.push(length % 2);
		length /= 2;
	}
	while(!st.empty())
	{
		tmp += to_string(st.top());
		st.pop();
	}
	return tmp;
}

vector<int> solution(string s)
{
    vector<int> answer;
	while(s.length()!=1)
	{
		s = step1(s);
		s = step2(s);
	}

	answer.push_back(ans1);
	answer.push_back(ans2);

    return answer;
}

int main()
{
    vector<int> v = solution("1111111");
	for (int i : v)
		cout << i << ' ';
    return 0;
}