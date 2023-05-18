#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	int NC = 0;
	int C = 0;
	int a;
	while(T--)
	{
		cin >> a;
		if (a == 0)
			NC++;
		else
			C++;
	}

	cout<< (NC>C ? "Junhee is not cute!" : "Junhee is cute!");

	return 0;
}