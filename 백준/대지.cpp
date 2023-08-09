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
	int T;
	cin >> T;

	int minX = 217400000;
	int maxX = -217400000;
	int minY = 217400000;
	int maxY = -217400000;

	
	int x, y;
	while (T--)
	{
		cin >> x >> y;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	if (T == 1)
	{
		cout << 0;
		return 0;
	}
	cout << (maxX - minX) * (maxY - minY);

	return 0;
}