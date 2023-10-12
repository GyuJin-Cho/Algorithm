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
	map<string, bool,greater<string>> m;
	int t;
	cin >> t;
	while(t--)
	{
		string name, commute;
		cin >> name >> commute;
		if (commute == "enter")
			m[name] = true;
		else if (commute == "leave")
			m[name] = false;
	}

	for(auto i : m)
	{
		if (i.second)
			cout << i.first << '\n';
	}

	return 0;
}