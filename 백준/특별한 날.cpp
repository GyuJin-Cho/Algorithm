#include<iostream>

using namespace std;

int main()
{
	int mon, day;
	cin >> mon >> day;

	if (mon < 2)
		cout << "Before";
	else if (mon == 2)
	{
		if (day == 18)
			cout << "Special";
		else if (day > 18)
			cout << "After";
		else if (day < 18)
			cout << "Before";
	}
	else
		cout << "After";

	return 0;
}