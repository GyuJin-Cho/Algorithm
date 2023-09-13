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
int d[4001][4001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	cin >> a >> b;
	int n = a.size();
	int m = b.size();
	a = " " + a;
	b = " " + b;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else
			{
				d[i][j] = 0;
			}
		}
	}
	int answer = -217400000;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			answer = max(answer, d[i][j]);
	cout << answer;
	return 0;
}