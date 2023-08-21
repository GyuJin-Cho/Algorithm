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
int d[31];
int main()
{
	int n;
	cin >> n;
	
	d[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		d[i] = d[i - 2] * 3;
		for (int j = i - 4; j >= 0; j -= 2)
		{
			d[i] += d[j] * 2;
		}
	}
	cout << d[n];
	return 0;
}