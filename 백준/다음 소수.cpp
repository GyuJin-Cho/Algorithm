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

bool IsPrime(long long n)
{
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		long long n;
		cin >> n;
		if (n >= 0 && n <= 2)
			cout << 2 << '\n';
		else if (n == 3)
			cout << 3;
		else 
		{
			while (!IsPrime(n))
				n++;
			cout << n << '\n';
		}
	}

	return 0;
}