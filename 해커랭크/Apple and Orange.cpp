#include<iostream>

using namespace std;

int main()
{
	int s;
	int t;
	cin >> s >> t;
	int a, b;
	cin >> a >> b;
	int m, n;
	cin >> m >> n;
	int AppleCount = 0;
	int OrangeCount = 0;
	for (int i = 0; i < m; i++)
	{
		int Apple;
		cin >> Apple;
		if (a + Apple >= s && a + Apple <= t)
			AppleCount++;
	}
	for (int i = 0; i < n; i++)
	{
		int Orange;
		cin >> Orange;
		if (b + Orange >= s && b + Orange <= t)
			OrangeCount++;
	}
	cout << AppleCount << endl << OrangeCount;
	return 0;
}