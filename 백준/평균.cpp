#include<iostream>
#include <stdio.h>
using namespace std;
double num[1001];
int main()
{
	int a,b;
	int max = -1;
	cin >> a;
	float answer = 0.0;
	for (int i = 0; i < a; i++)
	{
		cin >> b;
		if (max < b)
		{
			max = b;
		}
		num[i] = b;
	}
	for (int i = 0; i < a; i++)
	{
		num[i] = num[i] / max * 100.0;
		answer += num[i];
	}
	answer /= a;
	printf("%.2f", answer);
	return 0;
}