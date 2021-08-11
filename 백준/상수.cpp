#include<iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int as[3];
	int bs[3];
	cin >> a >> b;
	as[2] = a / 100;
	as[1] = (a / 10)-(as[2]*10);
	as[0] = a - (as[2] * 100 + as[1] * 10);
	bs[2] = b / 100;
	bs[1] = (b / 10) - (bs[2] * 10);
	bs[0] = b - (bs[2] * 100 + bs[1] * 10);
	a = as[2] + (as[1] * 10) + (as[0] * 100);
	b = bs[2] + (bs[1] * 10) + (bs[0] * 100);
	if (a > b)
		cout << a;
	else
		cout << b;
	return 0;
}