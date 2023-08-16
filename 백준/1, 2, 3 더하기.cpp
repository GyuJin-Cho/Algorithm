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
int D[12];
int main()
{
	D[0] = 1;
	for (int i = 1; i <= 10; i++)
	{
		if (D[i - 1] >= 0)
		{
			D[i] += D[i - 1];
		}
		if (D[i - 2] >= 0)
		{
			D[i] += D[i - 2];
		}
		if (D[i - 3] >= 0)
		{
			D[i] += D[i - 3];
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << D[n]<<'\n';
	}
	return 0;
}