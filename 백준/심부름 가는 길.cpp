#include<iostream>

using namespace std;
int main()
{
	int time=0,a;
	for(int i=0;i<4;i++)
	{
		cin >> a;
		time += a;
	}

	int Minute = time / 60;
	int Second = time % 60;
	cout << Minute << '\n' << Second;
	return 0;
}