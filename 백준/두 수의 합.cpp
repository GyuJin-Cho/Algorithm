#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;

	int start = 0;
	int end = n-1;
	int Sum = 0;
	int cnt = 0;
	sort(arr, arr + n);
	while (start < end)
	{
		Sum = arr[start] + arr[end];
		if (Sum < x)
		{
			start++;
		}
		else if (Sum > x)
		{
			end--;
			
		}
		else if(Sum==x)
		{
			cnt++;
			end--;
		}
	}
	cout << cnt;
	return 0;
}