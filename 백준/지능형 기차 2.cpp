#include<iostream>

using namespace std;

int main()
{
	int L, I;
	int aboveP=0;
	int ans = -217400000;
	for(int i=0;i<10;i++)
	{
		cin >> L >> I;
		aboveP -= L;
		aboveP += I;
		ans = max(ans, aboveP);
	}
	cout << ans;
	return 0;
}