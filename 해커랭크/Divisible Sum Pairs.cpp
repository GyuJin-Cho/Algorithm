#include<iostream>

using namespace std;

int main()
{
	int ar[101];
	int n, k;
	cin >> n >> k;
	for (int i = 0;i < n; i++)
	{
		cin >> ar[i];
	}
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if ((ar[i] + ar[j]) % k == 0)
				count++;
		}
	}
	cout << count;
	return 0;
}