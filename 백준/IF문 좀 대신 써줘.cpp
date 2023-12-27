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
	map<int, string> um;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		int x;
		string y;
		cin >> y >> x;
		um.insert(pair<int, string>(x, y));
	}

	map<int, string>::iterator iter;

	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		iter = um.lower_bound(x);
		cout << iter->second << '\n';
	}
	return 0;
}