#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int T = 0;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		stack<char> st;
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); ++j)
		{
			if (st.empty() || s[j] == '(')
				st.push(s[j]);
			else if (st.top() == '(')
				st.pop();
		}

		if (st.empty()) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}

	return 0;
}