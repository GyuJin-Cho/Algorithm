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

long long d[1001];
int main()
{
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		d[i] = d[i - 1] + 1;
		for(int j=1;j<=i-3;j++)
		{
			long long cur = d[i - j - 2] * (j + 1);
			d[i] = max(d[i], cur);

		}
	}
	cout << d[n];
	return 0;
}