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
int n, m;
int a[1000];
int d[1000][1000];

int GO(int index, int cnt)
{
	if (index == n)
		return 0;
	int &ans = d[index][cnt];
	if (ans != -1)
		return ans;
	int space = (m - (cnt - 1));
	int cost = pow(space, 2);
	ans = GO(index + 1, a[index] + 1) + cost;
	if(cnt+a[index]<=m)
	{
		int cur = GO(index + 1, cnt + a[index] + 1);
		if (ans > cur)
			ans = cur;
	}
	return ans;
}

int main()
{
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	memset(d, -1, sizeof(d));
	cout << GO(1, a[0] + 1);
	return 0;
}