#include<iostream>

using namespace std;

int main()
{
	int max = -1;
	int c = 0;
	int count = 0;
	
	for (int i = 1; i <= 9; i++)
	{
		cin >> c;
		if (max < c)
		{
			max = c;
			count = i;
		}
		
	}
	cout << max << endl << count;
	return 0;
}