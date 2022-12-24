#include<iostream>
#include<cmath>

using namespace std;
int a[1000000];

int main()
{
	while(1)
	{
		int n;
		cin >> n;
		int cnt = 0;
		
		for (int i = 0; i <= n * 2; i++)
			a[i] = 0;

		if (n == 0)
			break;

		for (int i = 2; i <= 2 * n; i++)
		{
			if (a[i] == 0)
				a[i] = 0;
			for (int j = i + i; j <= 2 * n; j += i)
			{
				if(a[j]!=1)
					a[j] = 1;
			}
		}
		for(int i=n+1;i<=2*n;i++)
		{
			if (a[i] == 0)
				cnt++;
		}
		cout << cnt<<'\n';
	}
	return 0;
}