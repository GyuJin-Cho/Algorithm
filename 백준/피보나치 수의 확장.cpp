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

constexpr long long MOD = 1000000000;
constexpr int MAX = 1000001;
int main()
{
	int n, flag=1;
	cin >> n;
	if(n<0)
	{
		n *= -1;
		if (n % 2 == 0)
			flag = -1;
	}
	if (n == 0)
		flag = 0;

	long long arr[MAX];
	arr[0] = 0;
	arr[1] = 1;

	for(int i=2;i<=n;i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % MOD;
	}
	cout << flag << '\n' << (arr[n]%MOD);
	return 0;
}