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
long long ans;
void DivideConquer(int n, int c ,int r)
{
	if (n == 0)
		return;
	int size = 1 << n;
	long long half = size / 2;
	if (c / half == 0 && r / half == 0)
	{
		ans += half * half * 0;
		DivideConquer(n - 1, c % half, r % half);
	}
	else if (c / half == 0 && r / half == 1)
	{
		ans += half * half * 1;
		DivideConquer(n - 1, c % half, r % half);
	}
	else if (c / half == 1 && r / half == 0)
	{
		ans += half * half * 2;
		DivideConquer(n - 1, c % half, r % half);
	}
	else
	{
		ans += half * half * 3;
		DivideConquer(n - 1, c % half, r % half);
	}
}
int main()
{
	int N, C, R;
	cin >> N >> C >> R;
	DivideConquer(N, C, R);
	cout << ans;

	return 0;
}