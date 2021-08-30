#include<iostream>
#include<cmath>

using namespace std;

int a[101][101];
int main()
{
	int T;
	cin >> T;
	int sum1=0;
	int sum2=0;
	for (int i = 0; i < T; i++)
	{
		for (int j = 0; j < T; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < T; i++)
	{
		sum1 += a[i][i];
	}
	int count = 0;
	for (int i = T - 1; i >= 0; i--)
	{
		sum2 += a[count][i];
		count++;
	}
	cout << abs(sum1 - sum2);
	return 0;
}
