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
double DP[10001];
int main()
{
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	DP[0] = v[0];
	double ans = v[0];
	for (int i = 1; i < n; i++)
	{
		double tmp;
		if (v[i] * DP[i - 1] >= v[i])
			tmp = v[i] * DP[i-1];
		else
			tmp = v[i];
		DP[i] = tmp;
		ans = max(ans, tmp);
	}

	printf("%.3f", ans);

	return 0;
}