#include<iostream>
#include<cmath>
#define MOD 1234567891
using namespace std;

int main()
{
	int n;
	cin >> n;
	string answer;
	cin >> answer;
	long long result=0;
	long long tmp=1;
	for (int i = 0; i < n; i++)
	{
		result += ((answer[i] - 'a' + 1) * tmp) % MOD;
		tmp *= 31;
		tmp %= MOD;
	}
	cout << result%MOD;
	return 0;
}