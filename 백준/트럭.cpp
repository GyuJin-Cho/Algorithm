#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, w, l;
	cin >> n >> w >> l;
	vector<int> Truck(n);
	for (int i = 0; i < n; i++)
		cin >> Truck[i];

	int ans = 0;
	int sum = 0;
	vector<int> Bridgh;
	int TruckCheck = 0;
	while (1)
	{
		ans++;
		if (Bridgh.size() == w)
		{
			sum -= Bridgh[0];
			Bridgh.erase(Bridgh.begin());
		}

		if (sum + Truck[TruckCheck] <= l)
		{
			if (TruckCheck == Truck.size() - 1)
			{
				ans += w;
				break;
			}
			Bridgh.push_back(Truck[TruckCheck]);
			sum += Truck[TruckCheck];
			TruckCheck++;
		}
		else
		{
			Bridgh.push_back(0);
		}
	}
	cout << ans;
	return 0;
}