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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,N,num;
	cin >> T;
	stack<int> s;
	while (T--)
	{
		cin >> N;
		if (N == 1)
		{
			cin >> num;
			s.push(num);
		}
		else if (N == 2)
		{
			if (s.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << s.top() << '\n';
			s.pop();
		}
		else if (N == 3)
		{
			cout << s.size() << '\n';
		}
		else if (N == 4)
		{
			if (s.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else
		{
			if (s.empty())
			{
				cout << -1 << '\n';
				continue;
			}
			cout << s.top() << '\n';
		}
	}

	return 0;
}