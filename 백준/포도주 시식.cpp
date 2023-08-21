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
int d[10001];
int a[10001];
int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> a[i];
	}

	d[1] = a[1];
	d[2] = a[1] + a[2];

	for (int i = 3; i <= T; i++)
	{
		d[i] = max(d[i - 1], max(d[i - 2] + a[i], d[i - 3] + a[i - 1] + a[i]));
	}
	cout << d[T];

	return 0;
}