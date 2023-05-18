#include<iostream>
#include<vector>

using namespace std;
#define INF 217400000
int main()
{
	int sum = 0;
	int Min = INF;
	int N;
	for(int i=0;i<7;i++)
	{
		cin >> N;
		if(N%2==1)
		{
			sum += N;
			Min = min(Min, N);
		}
	}
	if (Min == INF)
		cout << -1;
	else
		cout << sum << '\n' << Min;

	return 0;
}