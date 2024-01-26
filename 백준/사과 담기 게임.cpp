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
	int n, m, j;
	cin >> n >> m >> j;
	int l = 1, r = 0;
	int ans = 0;
	for(int i=0;i<j;i++)
	{
		r = l + m - 1;
		int tmp;
		cin >> tmp;
		if(tmp>=l&&tmp<=r)
			continue;
		if(l>tmp)
		{
			ans += l - tmp;
			l = tmp;
		}
		else if(l<tmp)
		{
			ans += tmp - r;
			l += tmp - r;
		}
	}
	cout << ans;
	return 0;
}