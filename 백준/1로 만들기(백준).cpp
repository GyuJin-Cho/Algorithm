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
int d[1000001];
int main()
{
	int n;
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
		}
		if (i % 3 == 0 &&d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
		}
	}
	cout << d[n];
	return 0;
}