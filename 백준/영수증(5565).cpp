#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int total;
	cin >> total;
	int price;
	for(int i=0;i<9;i++)
	{
		cin >> price;
		total -= price;
	}
	cout << total;
	return 0;
}