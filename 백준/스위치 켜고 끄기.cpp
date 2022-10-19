#include<iostream>

using namespace std;

bool Switch[102];

void Solve(int Gender, int Number, int n)
{
	if (Gender == 1)
	{
		for (int i = 1; i <= n; i++)
		{
			if (i * Number > n)
				break;
			Switch[i * Number] = !Switch[i * Number];
		}
	}
	else
	{
		int i = 1;
		Switch[Number] = !Switch[Number];
		while (1)
		{
			if (Number - i >= 1 && Number + i <= n)
			{
				if (Switch[Number - i] == Switch[Number + i])
				{
					Switch[Number - i] = !Switch[Number - i];
					Switch[Number + i] = !Switch[Number + i];
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
			i++;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> Switch[i];
	}
	int H;
	cin >> H;
	for (int i = 0; i < H; i++)
	{
		int Gender, Number;
		cin >> Gender >> Number;
		Solve(Gender, Number,n);
	}
	int i;
	for (i = 1; i <= n; i++)
	{
		cout << Switch[i] << " ";
		if (i % 20 == 0)
			cout << '\n';
	}
	return 0;
}