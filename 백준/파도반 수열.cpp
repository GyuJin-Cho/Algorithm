#include<iostream>
using namespace std;
long long p[101];
int main()
{
	cin.tie(0);
	cout.tie(0);
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	for (int i = 3; i < 101; i++)
	{
		p[i] = p[i - 3] + p[i - 2];
	}
	int T;
	cin >> T;
	int n;
	while (T--)
	{
		cin >> n;
		cout << p[n] << '\n';
	}
} 