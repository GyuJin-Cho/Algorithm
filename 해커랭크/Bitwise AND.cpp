#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		int k;
		int Max = 0;
		cin >> n >> k;
		for(int j=1;j<n;j++)
			for (int z = j + 1; z <= n; z++)
			{
				if ((j & z) > Max && (j & z) < k)
				{
					Max = (j & z);
				}
			}
		cout << Max << endl;
	}
	return 0;
}