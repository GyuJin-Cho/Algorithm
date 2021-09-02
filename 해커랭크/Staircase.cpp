#include<iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	int count = 1;
	for (int i = 0; i <T; i++)
	{
		for (int j = T; j > count; j--)
		{
			cout << ' ';
		}
		for (int z = 0; z <count ; z++)
		{
			cout << '*';
		}
		count++;
		cout << endl;
	}
	return 0;
}