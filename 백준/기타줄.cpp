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
	int n, m;
	int set = 1000, single = 1000;
	cin >> n >> m;
	
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		set = min(set, x);
		single = min(single, y);
	}

	cout << min({ (n / 6 + 1) * set,n / 6 * set + n % 6 * single,n * single });
	return 0;
}