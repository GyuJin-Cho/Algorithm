#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	int N, W, L;
	cin >> N >> W >> L;
	vector<int> Truck;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		Truck.push_back(a);
	}

	int count = 0;
	int sum = 0;
	vector<int> v;
	int TruckCheck = 0;
	while (1)
	{
		count++;
		if (v.size() == W)
		{
			sum -= v[0];
			v.erase(v.begin());
		}

		if (sum + Truck[TruckCheck] <= L)
		{
			if (TruckCheck == Truck.size() - 1)
			{
				count += W;
				break;
			}

			v.push_back(Truck[TruckCheck]);
			sum += Truck[TruckCheck];
			TruckCheck++;
		}
		else
		{
			v.push_back(0);
		}

	}
	cout << count;

	return 0;
}