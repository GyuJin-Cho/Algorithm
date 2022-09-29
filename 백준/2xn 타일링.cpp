#include<iostream>

using namespace std;

int DP[1001] = { 0, };

int main()
{
	DP[0] = 1;
	DP[1] = 2;
	int n = 0;
	cin >> n;
	int answer = 0;
	for (int i = 2; i < n; i++)
	{
		DP[i] = (DP[i - 1] + DP[i - 2]) % 10007;
	}
	cout << DP[n-1];
	return 0;
}