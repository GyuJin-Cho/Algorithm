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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> sumarr(n);
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (i == 0)
			sumarr[i] = num;
		else
			sumarr[i] = sumarr[i - 1] + num;
	}

	for (int i = 0; i < m; i++)
	{
		int s, j;
		cin >> s >> j;
		if (s - 2 < 0)
			cout << sumarr[j - 1]<<'\n';
		else
			cout << sumarr[j-1] - sumarr[s - 2]<<'\n';
	}

	return 0;
}