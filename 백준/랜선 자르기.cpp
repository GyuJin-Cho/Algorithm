#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	long long k, N,M;
	long long L = 1;
	long long H = -1;
	long long cnt;
	long long res = 0;
	cin >> k >>N;
	vector<int> a(k);
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		if (H < a[i])
		{
			H = a[i];
		}
	}

	while (L <= H)
	{
		M = (L + H) / 2;
		cnt = 0;
		for (int i = 0; i < k; i++)
		{
			cnt += a[i] / M;
		}
		if (cnt < N)
		{
			H = M - 1;
		}
		else
		{
			L = M + 1;
			if (res < M)
			{
				res = M;
			}
		}
	}
	cout << res;
	return 0;
}