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
int d[1001][1001];
int v[1001][1001];
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
				v[i][j] = 1;
			}
			else
			{
				if(d[i-1][j]<d[i][j-1])
				{
					d[i][j] = d[i][j - 1];
					v[i][j] = 2;
				}
				else
				{
					d[i][j] = d[i - 1][j];
					v[i][j] = 3;
				}
			}
		}
	}
	cout << d[n][m]<<'\n';
	string answer = "";
	while(n>0&&m>0)
	{
		if(v[n][m]==1)
		{
			answer += a[n];
			n--;
			m--;
		}
		else if(v[n][m]==2)
		{
			m--;
		}
		else
		{
			n--;
		}
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}