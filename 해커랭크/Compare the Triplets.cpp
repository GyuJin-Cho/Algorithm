#include<iostream>

using namespace std;

int main()
{
	int a[3];
	int b[3];
	int acount = 0;
	int bcount = 0;
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 3; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < 3; i++)
	{
		if (a[i] > b[i])
			acount++;
		else if (a[i] < b[i])
			bcount++;
	}
	cout << acount << ' ' << bcount;
	return 0;
}