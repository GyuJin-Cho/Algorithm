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
	string s, e, q;
	cin >> s >> e >> q;
	int start_sec = (stoi(s.substr(0, 2))*60) +stoi(s.substr(3, 2));
	int end_sec = (stoi(e.substr(0, 2)) * 60) + stoi(e.substr(3, 2));
	int q_sec = (stoi(q.substr(0, 2)) * 60) + stoi(q.substr(3, 2));

	string time,name;
	unordered_set<string> entry;
	int ans = 0;
	while(cin>>time>>name)
	{
		int tsec = (stoi(time.substr(0, 2)) * 60) + stoi(time.substr(3, 2));
		if(tsec<=start_sec)
		{
			entry.insert(name);
		}

		if(tsec>=end_sec&&tsec<=q_sec)
		{
			if(entry.find(name)!=entry.end())
			{
				ans++;
				entry.erase(name);
			}
		}

	}
	cout << ans;
	return 0;
}