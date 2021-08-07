#include<iostream>

using namespace std;

int main()
{
	string a;
	int b;
	cin >> b;
	int f;
	int count = 1;
	for (int i = 0; i < b; i++)
	{
		cin >> f >> a;
		for (int j = 0; j < a.length(); j++)
		{
			for (int z = 0; z < f; z++)
			{
				cout << a[j];
			}
		}
		cout << endl;
		
	}
	return 0;
}