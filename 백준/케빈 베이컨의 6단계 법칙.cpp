#include<iostream>

using namespace std;

int Friend[101][101];

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int v, e;
		cin >> v >> e;
		Friend[v][e] = 1;
		Friend[e][v] = 1;
	}

	for (int i = 1; i < 101; i++)
	{
		for (int j = 1; j < 101; j++)
		{
			if (Friend[i][j] != 1&&i!=j)
			{
				Friend[i][j] = 999999999;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				Friend[j][k] = min(Friend[j][k], Friend[j][i] + Friend[i][k]);
			}
		}
	}

	int val = 99999999;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			temp += Friend[i][j];
		}
		if (temp < val)
		{
			val = temp;
			ans = i;
		}
	}
	cout << ans;
	return 0;
}