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
int a[1000][2];
int d[1000][1000];

int GO(int x, int y)
{
	if (d[x][y])
		return d[x][y];
	if (x == y)
		return 0;
	if (x + 1 == y)
		return a[x][0] * a[x][1] * a[y][1];
	int& ans = d[x][y];
	ans = -1;
	for(int k=x;k<=y-1;k++)
	{
		int t1 = GO(x, k);
		int t2 = GO(k + 1, y);
		if (ans == -1 || ans > t1 + t2 + a[x][0] * a[k][1] * a[y][1])
			ans = t1 + t2 + a[x][0] * a[k][1] * a[y][1];
	}
	return ans;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i][0] >> a[i][1];
	}
	cout << GO(0, n - 1);
	return 0;
}