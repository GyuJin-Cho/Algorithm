#include<iostream>
#include<algorithm>
using namespace std;

long long arr[100001];

bool bSearch(int start, int end, long long k)
{
	int mid;
	while(start<=end)
	{
		mid = start + (end - start) / 2;
		if (arr[mid] == k)
			return true;
		if (arr[mid] < k)
			start = mid + 1;
		else
			end = mid - 1;
	}
	return false;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	long long count = 0;
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++)
	{
		if (bSearch(i + 1, n - 1, arr[i] + k)) 
		{
			count++;
		}
	}
	cout << count;
	return 0;
}