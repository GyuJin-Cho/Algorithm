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
int d[101][100001];
int a[101];
int w[101];
int main()
{
	int n, k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> w[i] >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			d[i][j] = d[i - 1][j];
			if(j-w[i]>=0)
			{
				d[i][j] = max(d[i][j], d[i - 1][j - w[i]] + a[i]);
			}
		}
	}
	cout << d[n][k];
	return 0;
}