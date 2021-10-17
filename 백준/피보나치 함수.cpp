#include<iostream>

using namespace std;
int zerocount = 0;
int onecount = 0;
int fibo(int n)
{
	int temp;
	int before = 0;
	int cur = 1;
	if (n == 0)
	{
		zerocount++;
		return 0;
	}
	else if (n == 1)
	{
		onecount++;
		return 1;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			temp = cur;
			cur = before + cur;
			before = temp;
			if (cur == 1)
			{
				onecount++;
			}
		}
		return cur;
	}
		
}

int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		zerocount = 0;
		onecount = 0;
		int n;
		cin >> n;
		fibo(n);
		printf("%d %d\n", zerocount, onecount);
	}
	
	return 0;
}