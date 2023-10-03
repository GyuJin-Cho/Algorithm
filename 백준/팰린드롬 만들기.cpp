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
int d[5001][5001];
int a[5001];
int b[5001];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[n - i + 1] = a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]==b[j])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
				
			}
			else
			{
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	cout << n - d[n][n];
	return 0;
}