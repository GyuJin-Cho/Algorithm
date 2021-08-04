#include<iostream>

using namespace std;

int main()
{
	int T[8];
	int count = 0;
	bool ascending = false;
	for (int i = 0; i < 8; i++)
	{
		cin >> T[i];
	}
	count = 0;
	for (int i = 0; i < 8; i++)
	{
		if (T[i] == i + 1)
		{
			count++;
			continue;
		}
	}
	if (count == 8)
	{
		cout << "ascending";
		return 0;
	}
	count = 0;
	int c = 0;
	for (int i = 7; i >= 0; i--)
	{
		if (T[c] == i + 1)
		{
			count++;
			c++;
			continue;
		}
		c++;
	}
	if (count == 8)
	{
		cout << "descending";
		return 0;
	}
	count = 0;
	cout << "mixed";
	return 0;
}