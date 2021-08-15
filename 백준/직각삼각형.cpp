#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	long long x, y, z;
	long long temp = -1;
	
	while (1)
	{
		temp = -1;
		bool a[3] = { false, };
		cin >> x >> y >> z;
		if (x == 0 && y == 0&&z == 0)
			break;
		if (temp < x)
		{
			temp = x;
			a[0] = true;
		}
			
		if (temp < y)
		{
			temp = y;
			a[0] = false;
			a[1] = true;
		}
		if (temp < z)
		{
			temp = z;
			a[0] = false;
			a[1] = false;
			a[2] = true;
		}
		if (a[0])
			if (temp * temp == (y * y) + (z * z))
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
		if (a[1])
			if (temp * temp == (x * x) + (z * z))
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
		if (a[2])
			if (temp * temp == (y * y) + (x * x))
				cout << "right" << endl;
			else
				cout << "wrong" << endl;
	}
	return 0;

}