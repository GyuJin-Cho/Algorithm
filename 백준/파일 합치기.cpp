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
int a[501];
int d[501][501];

int DP(int i, int j)
{
	if (i == j)
		return 0;
	if (d[i][j] != -1)
		return d[i][j];
	int& answer = d[i][j];
	int sum = 0;
	for (int k = i; k <= j; k++)
		sum += a[k];
	for (int k = i; k <= j - 1; k++)
	{
		int temp = DP(i, k) + DP(k + 1, j) + sum;
		if (answer == -1 || answer > temp)
			answer = temp;
	}
		
	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		memset(d, -1, sizeof(d));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << DP(1, n)<<'\n';
			

	}

	return 0;
}