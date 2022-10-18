#include<iostream>

using namespace std;
int arr[100001];
int main()
{
	cout.tie(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int start = -1;
	int end = -1;
	long long sum = 0;
	int ans = 99999999;
	while (end < N)
	{
		if (sum >= S)
		{
			start++;
			sum -= arr[start];
		}
		else if (sum <= S)
		{
			end++;
			sum += arr[end];
		}
		
		if (sum >= S)
		{
			ans = min(ans, end - start);
		
		}
	}
	if (ans == 99999999)
	{
		ans = 0;
	}
	cout << ans;
	return 0;
}