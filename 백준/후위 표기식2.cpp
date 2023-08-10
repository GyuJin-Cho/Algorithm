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
	int n;
	cin >> n;
	cin >> s;
	vector<int> v(n);
	stack<double> st;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.push(v[s[i] - 'A']);
		}
		else
		{
			if (!st.empty())
			{
				double tmp = st.top();
				st.pop();
				if (s[i] == '+')
				{
					tmp = st.top() + tmp;
				}
				else if (s[i] == '-')
				{
					tmp = st.top() - tmp;
				}
				else if (s[i] == '*')
				{
					tmp = st.top() * tmp;
				}
				else if (s[i] == '/')
				{
					tmp = st.top() / tmp;
				}
				st.pop();
				st.push(tmp);
			}
		}
	}

	printf("%.2f", st.top());

	return 0;
}