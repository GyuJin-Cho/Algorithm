#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int hour;
	int min;
	cin >> hour >> min;
	if (min - 45 < 0)
	{
		min = min + 60;
		min -= 45;
		hour--;
	}
	else
	{
		min -= 45;
	}
	if (hour < 0)
		hour = 23;
	cout << hour << " " << min;
	return 0;
}