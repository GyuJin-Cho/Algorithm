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
	int n,h;
	cin >> n;
	stack<pair<int, int>>s;
	for(int i=0;i<n;i++)
	{
		cin >> h;
		while(!s.empty())
		{
			if(h<s.top().second)
			{
				cout << s.top().first<<' ';
				break;
			}
			s.pop();
		}
		if (s.empty())
			cout << 0 << ' ';
		s.push(make_pair(i + 1, h));
	}
	return 0;
}