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
int n, s, m;
int a[101];
bool d[101][1001];
int main()
{
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[0][s] = true;
	for(int i=0;i<=n-1;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(!d[i][j])
				continue;
			if (j - a[i + 1] >= 0)
				d[i + 1][j - a[i + 1]] = true;
			if (j + a[i + 1] <= m)
				d[i + 1][j + a[i + 1]] = true;
		}
	}
	int answer = -1;
	for (int i = 0; i <= m; i++)
		if (d[n][i])
			answer = i;
	cout << answer;
	return 0;
}