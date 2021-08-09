#include<iostream>

using namespace std;

int main()
{
	int a, d;
	int z;
	cin >> a >> d;
	for (int i = 0; i < a; i++)
	{
		cin >> z;
		if (d > z)
		{
			cout << z << " ";
		}
	}
	return 0;
}