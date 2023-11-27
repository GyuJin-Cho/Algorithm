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
	int T,n;
	cin >> T;
	while(T--)
	{
		cin >> n;
		vector<int> stock(n);
		for (int i = 0; i < n; i++)
			cin >> stock[i];

		long long ans = 0;
		int Max = -1;
		for(int i=n-1;i>=0;i--)
		{
			Max = max(Max, stock[i]);
			ans += Max - stock[i];
		}
		cout << ans<<'\n';
	}
	
	return 0;
}