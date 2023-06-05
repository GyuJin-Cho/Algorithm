#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ERROR 0.00000001
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<double> Num(N+1);
	for (int i = 1; i <= N; i++)
		cin >> Num[i];

	sort(Num.begin()+1, Num.end());
	
	double sum = 0;
	for(int i=K+1;i<=N-K;i++)
	{
		sum += Num[i];
	}
	double TMans = sum /(N-2*K);
	printf("%.2lf'\n", floor(TMans * 100 + 0.5) / 100);
	for(int i=1;i<=K;i++)
	{
		Num[i] = Num[K + 1];
		Num[N - i + 1] = Num[N - K];
	}
	sum = 0;
	for (int i = 0; i < Num.size(); i++)
	{
		sum += Num[i];
	}
	double AMans = sum/N;
	printf("%.2lf", floor(AMans*100+0.5)/100);
	return 0;
}