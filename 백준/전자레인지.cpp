#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int AMin = 300;
	int BMin = 60;
	int CMin = 10;
	int Acnt = 0;
	int Bcnt = 0;
	int Ccnt = 0;

	if(T>=AMin)
	{
		Acnt = T / AMin;
		T = T - (Acnt * AMin);
	}
	if(T>=BMin)
	{
		Bcnt = T / BMin;
		T = T - (Bcnt * BMin);
	}
	if(T>=CMin)
	{
		Ccnt = T / CMin;
		T = T - (Ccnt * CMin);
	}


	if (T == 0)
		cout << Acnt << ' ' << Bcnt << ' ' << Ccnt;
	else
		cout << -1;
	return 0;
}