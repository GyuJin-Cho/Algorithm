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

int n;
int t[20];
int p[20];
int d[20];
int DP(int day)
{
	if (day == n + 1)
	{
		return 0;
	}
	if (day > n + 1)
	{
		return -21740000;
	}
	if (d[day] != -1)
	{
		return d[day];
	}
	int t1 = DP(day + 1);
	int t2 = p[day] + DP(day + t[day]);
	d[day] = max(t1, t2);
	return d[day];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
		d[i] = -1;
	}

	cout << DP(1);

	return 0;
}