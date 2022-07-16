#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n;
	int cost;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cin >> cost;

	sort(v.begin(), v.end());

	int start = 0;
	int end = v[n-1];
	int result;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += min(v[i], mid);
		}
		if (cost >= sum)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << result;
}