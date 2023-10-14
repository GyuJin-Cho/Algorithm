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

int GCD(long a, long b)
{
	if (b > a) 
		return GCD(b, a);
	if (a % b == 0) 
		return b;
	else 
		return GCD(b, a % b);
}
int main()
{
	long up, down, up1, down1, N, M;
	cin >> up >> down >> up1 >> down1;
	N = down1 * up + up1 * down;
	M = down1 * down;

	cout << N / GCD(N, M) << ' ' << M / GCD(N, M);
}