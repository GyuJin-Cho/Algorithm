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

long long func(int n, int num)
{
	int tmp = 0;

	for(long long i=num;n/i>=1;i*=num)
	{
		tmp += n / i;
	}
	return tmp;
}

int main()
{
	int n, m;
	long long five = 0;
	long long two = 0;

	cin >> n >> m;

	five = func(n, 5) - func(n - m, 5) - func(m, 5);
	two = func(n, 2) - func(n - m, 2) - func(m, 2);

	cout << min(five, two);

	return 0;
}