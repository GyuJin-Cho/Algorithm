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
int n, l, r, x;
int a[15];
bool c[15];
int DFS(int index)
{
	if(index==n)
	{
		int cnt = 0;
		int sum = 0;
		int hard = -1;
		int easy = -1;
		for(int i=0;i<n;i++)
		{
			if(!c[i])
				continue;
			sum += a[i];
			cnt += 1;
			if (hard == -1 || hard < a[i])
				hard = a[i];
			if (easy == -1 || easy > a[i])
				easy = a[i];
		}
		if (cnt >= 2 && l <= sum && sum <= r && hard - easy >= x)
			return 1;
		else
			return 0;
	}
	c[index] = true;
	int cnt1 = DFS(index + 1);
	c[index] = false;
	int cnt2 = DFS(index + 1);
	return cnt1 + cnt2;
}
int main()
{
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << DFS(0);
	return 0;
}