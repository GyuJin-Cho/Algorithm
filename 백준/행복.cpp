#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int Min = 2174000;
	int Max = -2174000;
	int num;
	while(n--)
	{
		cin >> num;
		Min = min(num, Min);
		Max = max(num, Max);
	}
	cout << Max - Min;
	return 0;
}