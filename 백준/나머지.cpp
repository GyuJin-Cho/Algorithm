#include<iostream>

using namespace std;

int main()
{
	int a[10];
	bool b[10] = { false, };
	int count = 10;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
		a[i] = a[i] % 42;
	}
	for (int i = 0; i < 10; i++)
	{
		b[i] = true;
		for (int j = 0; j < 10; j++)
		{
			if (a[i] == a[j]&&b[j]==false)
			{
				count--;
				b[j] = true;
			}
		}
	}
	cout << count;
	return 0;
}