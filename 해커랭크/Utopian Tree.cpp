#include<iostream>

using namespace std;

int utopianTree(int n)
{
	int sum = 0;
	for(int i=0;i<=n;i++)
	{
		if (i == 0)
			sum += 1;
		else if(i%2==0)
		{
			sum += 1;
		}
		else
		{
			sum = sum * 2;
		}
	}
	return sum;
}

int main()
{
	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		int a;
		cin >> a;
		cout << utopianTree(a)<<endl;
	}
	
	return 0;
}