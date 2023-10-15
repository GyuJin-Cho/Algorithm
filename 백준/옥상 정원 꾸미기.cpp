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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	stack<int>s;
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		int height;
		cin >> height;

		if(s.empty())
		{
			s.push(height);
			continue;
		}

		while(!s.empty()&&s.top()<=height)
		{
			s.pop();
		}
		ans += s.size();

		s.push(height);
	}

	cout << ans;
	return 0;
}