#include<iostream>
#include<cmath>
using namespace std;
int arr[11];
int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	int m = 100;
	int sum[10] = { arr[0], };
	int i;
	for (i = 1; i < 10; i++)
	{
		sum[i] = sum[i-1] + arr[i];
		if (sum[i] > m)
		{
			if (abs(m - sum[i]) > abs(m-sum[i-1]) )
			{
				sum[i] -= arr[i];
			}
			break;

		}
	}
	if (i == 10)
		i--;
	cout << sum[i];
	return 0;
}