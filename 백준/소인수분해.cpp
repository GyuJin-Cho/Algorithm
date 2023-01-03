#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int mul=n;
	while(1)
	{
		if (mul == 1)
			break;
		for(int i=2;i<=mul;i++)
		{
			if(mul % i == 0)
			{
				cout << i << '\n';
				mul /= i;
				break;
			}
		}
	}

	return 0;
}