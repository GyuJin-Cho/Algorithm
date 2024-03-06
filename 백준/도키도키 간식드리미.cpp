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
	int cnt = 1, n;
	cin >> n;
	stack<int> s;
	vector<int>v(n);
	for (int i = 0; i < n; i++)
		cin>>v[i];
	bool ch = true;
	while (1)
	{
		if (cnt > n)
			break;
		if (!v.empty())
		{
			if (v[0] == cnt)
			{
				v.erase(v.begin());
				cnt++;
			}
			else
			{
				if (!s.empty())
				{
					if (s.top() == cnt)
					{
						s.pop();
						cnt++;
					}
					else
					{
						s.push(v[0]);
						v.erase(v.begin());
					}
				}
				else
				{
					s.push(v[0]);
					v.erase(v.begin());
				}
			}
		}
		else
		{
			if (s.top() == cnt)
			{
				s.pop();
				cnt++;
			}
			else
			{
				ch = false;
				break;
			}
		}
					
	}
	if (ch)
		cout << "Nice" << '\n';
	else
		cout << "Sad" << '\n';
	return 0;
}