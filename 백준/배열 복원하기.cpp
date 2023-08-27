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

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int h, w, x, y;
	cin >> h >> w >> x >> y;
	vector<vector<int>> a(h + x, vector<int>(w + y));
	for (int i = 0; i < h + x; i++)
	{
		for (int j = 0; j < w + y; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			a[i + x][j + y] -= a[i][j];
		}
	}
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}