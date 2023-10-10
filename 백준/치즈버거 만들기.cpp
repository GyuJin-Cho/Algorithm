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
	int b, c;
	cin >> b >> c;
	int ans = 0;

	b -= 2;
	c -= 1;
	ans += 3;
	if (b == 0 || c == 0)
	{
		cout << ans;
		return 0;
	}

	while(b!=0&&c!=0)
	{
		c--;
		b--;
		ans += 2;
	}
	cout << ans;
	return 0;
}