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
	int w, h,ans=0;
	cin >> h >> w;
	vector<int> world(w);
	for (int i = 0; i < w; i++)
		cin >> world[i];
	for (int i = 1; i < world.size(); i++)
	{
		int l = 0, r = 0;
		for (int j = 0; j < i; j++)
			l = max(l, world[j]);
		for (int j = world.size()-1; j > i; j--)
			r = max(r, world[j]);
		ans += max(0, min(l, r) - world[i]);
	}
	cout << ans;
	return 0;
}