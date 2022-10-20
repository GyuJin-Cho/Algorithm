#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <long long > V;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		V.push_back(x);
	}
	sort(V.begin(), V.end());

	long long start = 0;
	int EndMAX = -1;
	long long end = V[V.size() - 1] * m;
	long long result = end;
	while (start <= end)
	{
		long long mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < V.size(); i++)
		{
			sum += mid / V[i];
		}

		if (sum < m)
		{
			start = mid + 1;
		}
		else
		{
			result = mid;
			end = mid - 1;
		}
	}
	cout << result;

	return 0;
}