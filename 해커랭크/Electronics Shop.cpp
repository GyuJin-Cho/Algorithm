#include<iostream>
#include<algorithm>
using namespace std;
int key[1001];
int usb[1001];
int main()
{
	int c,n,m,Max=-1;
	cin >> c >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> key[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> usb[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(key[i]+usb[j]<=c)
			{
				Max = max(Max, key[i] + usb[j]);
			}

		}
	}
	cout << Max;
	return 0;
}