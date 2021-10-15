#include<iostream>
#include<cmath>
using namespace std;
int prime[1000001];

void Init()
{
	for (int i = 2; i <= 1000001; i++)
	{
		prime[i] = i;
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	Init();
	
	for (int i = 2; i <= sqrt(K); i++)
	{
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j <= K; j += i)
		{
			prime[j] = 0;
		}
	}

	for(int i=N;i<=K;i++)
	{
		if (prime[i] != 0)
		{
			printf("%d\n", prime[i]);
		}
	}

	return 0;
}