#include<iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	int cost = 1000 - T;
	int ChangeCost = 0;
	if (cost / 500 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 500);
		cost = cost - (500 * (cost / 500));
	}
	if (cost / 100 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 100);
		cost = cost - (100 * (cost / 100));
		
	}
	if (cost / 50 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 50);
		cost = cost - (50 * (cost / 50));
		
	}
	if (cost / 10 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 10);
		cost = cost - (10 * (cost / 10));
		
	}
	if (cost / 5 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 5);
		cost = cost - (5 * (cost / 5));
		
	}
	if (cost / 1 >= 1)
	{
		ChangeCost = ChangeCost + (cost / 1);
		cost = cost - (1 * (cost / 1));
		
	}

	cout << ChangeCost;
	return 0;
}