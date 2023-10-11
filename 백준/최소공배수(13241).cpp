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
int GCD(int a, int b)
{
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int main()
{
	long long int A, B, gcd;
	std::cin >> A >> B;

	gcd = GCD(A, B);
	std::cout << A * B / gcd;
}