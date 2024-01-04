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
int ans[501][501];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> ans[i][j];

	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans[i][j] = min(ans[i][k] + ans[k][j], ans[i][j]);

	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (ans[a-1][b-1] <= c)
			cout << "Enjoy other party\n";
		else
			cout << "Stay here\n";
	}
	return 0;
}