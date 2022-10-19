#include<iostream>

using namespace std;

bool Prison[102];

void PrisonInit()
{
	for (int i = 0; i < 102; i++)
		Prison[i] = false;
}

void solve(int n)
{
	PrisonInit();
	int count = 1;
	while (count <= n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i * count > n)
			{
				break;
			}
			else
			{
				Prison[i * count] = !Prison[i * count];
			}
		}
		count++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (Prison[i])
			ans++;
	}
	cout << ans << '\n';
}

int main()
{
	
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;

		cin >> n;
		solve(n);
	}


	return 0;
}