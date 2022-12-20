#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int Max = -1;
	int Min = 9999999999;
	int a;
	for(int i=0;i<n;i++)
	{
		cin >> a;
		if (Max < a)
			Max = a;
		if (Min > a)
			Min = a;
	}

	cout << Max * Min;

	return 0;
}