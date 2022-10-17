#include<iostream>

using namespace std;
int arr[10001] = { 0, };
int main()
{
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int start = -1;
	int end = -1;
	int Sum = 0;
	int cnt = 0;
	while (end < n && start <= end)
	{
		if (Sum > m)
		{
			start++;
			Sum -= arr[start];
		}
		else if (Sum < m)
		{
			end++;
			Sum += arr[end];
		}
		else
		{
			cnt++;
			end++;
			Sum += arr[end];
		}
	}
	cout << cnt;
	return 0;
}