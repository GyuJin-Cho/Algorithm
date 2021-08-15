#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	int a,n;
	vector<int> c;
	scanf_s ("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf_s("%d", &a);
		c.push_back(a);
	}
	sort(c.begin(), c.end());
	for (int i = 0; i < n; i++)
		printf("%d\n", c[i]);
}