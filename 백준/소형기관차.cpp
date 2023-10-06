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
int s[50001];
int a[50001];
int d[50001][4];
int cacul(int x, int y)
{
	return s[y] - s[x - 1];
}
int main()
{

	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}

	int m;
	cin >> m;

	for(int i=1;i<=3;i++)
	{
		for(int j=m*i;j<=n;j++)
		{
			d[j][i] = d[j - 1][i];
			d[j][i] = max(d[j][i], d[j - m][i - 1] + cacul(j - m + 1, j));
		}
	}
	cout << d[n][3];
	return 0;
}