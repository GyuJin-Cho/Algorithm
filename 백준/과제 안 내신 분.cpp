#include<iostream>
#include<map>

using namespace std;

int main()
{
	int n;
	map<int, int> m;
	for (int i = 0; i < 28; i++)
	{
		cin >> n;
		m[n]++;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (m[i] != 1)
		{
			cout << i << endl;
		}
	}

	return 0;
}