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

	int n, m;
	cin >> n >> m;

	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << min(4, (m + 1) / 2);
	else if (m < 7)
		cout << min(4, m);
	else
		cout << m - 2;

	return 0;
}