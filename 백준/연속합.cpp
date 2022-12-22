#include<iostream>

using namespace std;

int a[100000];
int b[100000];

int main()
{
	int n;
	int answer;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}

	answer = a[0];
	for(int i=0;i<n;i++)
	{
		b[i] = a[i];
		if (i == 0)
			continue;
		if(b[i]<b[i-1]+a[i])
		{
			b[i] = b[i - 1] + a[i];
		}
		if (b[i] > answer)
			answer = b[i];
		
	}

	cout << answer;
	return 0;
}