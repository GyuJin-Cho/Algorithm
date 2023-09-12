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

int a[2000];
bool d[2000][2000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		d[i][i] = true;
	for(int i=0;i<n-1;i++)
	{
		if (a[i] == a[i + 1])
			d[i][i + 1] = true;
	}
	for(int k=3;k<=n;k++)
	{
		for(int i=0;i<=n-k;i++)
		{
			int j = i + k - 1;
			if (a[i] == a[j] && d[i + 1][j - 1])
				d[i][j] = true;
		}
	}
	int m;
	cin >> m;
	while(m--)
	{
		int s, e;
		cin >> s >> e;
		cout << d[s - 1][e - 1] << '\n';
	}
	return 0;
}