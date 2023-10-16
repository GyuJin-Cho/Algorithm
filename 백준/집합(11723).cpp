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
	int T;
	cin >> T;
	int ans = 0;
	string t1;
	int num;
	while(T--)
	{
		
		cin >> t1;
		if(t1=="add")
		{
			cin >> num;
			num--;
			ans = (ans | (1 << num));
		}
		else if(t1=="remove")
		{
			cin >> num;
			num--;
			ans = (ans & (~(1 << num)));
		}
		else if(t1=="check")
		{
			cin >> num;
			num--;
			if (ans & (1 << num))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if(t1=="toggle")
		{
			cin >> num;
			num--;
			ans = ans ^ (1 << num);
		}
		else if(t1=="all")
		{
			ans = (1 << 20) - 1;
		}
		else
		{
			ans = 0;
		}
	}

	return 0;
}