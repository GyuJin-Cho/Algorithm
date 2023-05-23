#include<iostream>
#include<string>
#include <vector>

using namespace std;

int main()
{
	int day;
	cin >> day;

	if (day < 20 && day >= 10)
		day %= 10;
	else if (day < 30 && day >= 20)
		day %= 20;
	else if (day == 30)
		day = 0;
	int a;
	int ans = 0;
	for(int i=0;i<5;i++)
	{
		cin >> a;
		if (a == day)
			ans++;
	}
	cout << ans;

	return 0;
}