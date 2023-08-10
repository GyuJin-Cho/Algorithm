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
	string s= "";
	int answer = 0;
	cin >> s;
	stack<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			st.push(s[i]);
		else
		{
			if (s[i - 1] == '(')
			{
				st.pop();
				answer += st.size();
			}
			else
			{
				st.pop();
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}