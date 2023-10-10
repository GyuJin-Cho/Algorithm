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
int d[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 1; i <= 30; i++)
		d[1][i] = i;

	for (int i = 2; i <= 30; i++) 
	{
		for (int j = i; j <= 30; j++) 
		{
			for (int k = j - 1; k >= 1; k--) 
			{
				d[i][j] += d[i - 1][k];
			}
		}
	}

	int t; cin >> t;
	while (t--) 
	{
		int n, m;
		cin >> n >> m;
		cout << d[n][m]<<'\n';
	}
	return 0;
}