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

using namespace std;
int a[501][501];
int d[501][501];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}

	d[0][0] = a[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			d[i][j] = d[i - 1][j] + a[i][j];
			if (j - 1 >= 0 && d[i][j] < d[i - 1][j - 1] + a[i][j])
			{
				d[i][j] = d[i - 1][j - 1] + a[i][j];
			}
		}
	}


	int answer = d[n - 1][0];
	for (int i = 0; i < n; i++)
	{
		if (answer < d[n - 1][i])
		{
			answer = d[n - 1][i];
		}
	}
	cout << answer;
	return 0;
}