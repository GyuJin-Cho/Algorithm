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
	set<pair<int, int>> db;
	map<int, int>dict;
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n,m;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		int p, l;
		cin >> p >> l;
		db.insert({ l,p });
		dict[p] = l;
	}

	cin >> m;

	for(int i=0;i<m;i++)
	{
		string op;
		cin >> op;
		int p, l;
		if(op=="add")
		{
			cin >> p >> l;
			db.insert({ l,p });
			dict[p] = l;
		}
		else if(op=="recommend")
		{
			cin >> p;
			if (p == -1)
			{
				auto it = db.begin();
				cout << it->second << '\n';
			}
				
			else
			{
				auto it = db.rbegin();
				cout << it->second << '\n';
			}
				
		}
		else
		{
			cin >> p;
			db.erase({ dict[p],p });
			dict.erase(p);
		}
	}

	return 0;
}