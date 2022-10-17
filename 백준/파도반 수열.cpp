#include<iostream>
using namespace std;
long long p[101];
int main()
{
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	for (int i = 0; i < N; i++)
	{
		int T;
		cin >> T;
		
		for (int j = 3; j <= T; j++)
		{
			p[j] = p[j - 2] + p[j - 3];
		}
		cout << p[T]<<'\n';
		
	}
} 