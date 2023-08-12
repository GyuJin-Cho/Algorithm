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

int main()
{
	int n;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		sum += (n / i) * i;
	}
	cout << sum;
	return 0;
}