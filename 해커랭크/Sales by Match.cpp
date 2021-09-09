#include<iostream>
#include<algorithm>
using namespace std;
int arr[101];
int main()
{
	int n;
	cin >> n;
	int count = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	for(int i=0;i<n-1;i++)
	{
		if(arr[i]==arr[i+1])
		{
			arr[i] = -1;
			arr[i + 1] = -1;
			count++;
		}
	}
	cout << count;
	return 0;
}