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
#include<list>

using namespace std;

int main()
{
	string s;
	cin >> s;
	list<char> li;
	for (int i = 0; i < s.size(); i++)
	{
		li.push_back(s[i]);
	}

	int t;
	cin >> t;
	
	list<char>::iterator cur = li.end();

	while (t--)
	{
		char a;
		cin >> a;
		if (a == 'L')
		{
			if(cur!=li.begin())
				cur--;
		}
		else if (a == 'D')
		{
			if (cur != li.end())
				cur++;
		}
		else if (a == 'B')
		{
			if (cur != li.begin())
			{
				cur = li.erase(--cur);
			}
				
		}
		else
		{
			char p;
			cin >> p;
			li.insert(cur,p);
		}
	}

	for (auto i : li)
	{
		cout << i;
	}

	return 0;
}