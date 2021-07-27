#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int check[26];
int Max = -1;
int idx = -1;
int main()
{
	string a;
	getline(cin, a);
	string tmp;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 'A' && a[i] <= 'Z')
		{
			tmp += a[i];
		}
		else
		{
			tmp += a[i]-32;
		}
		
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		check[tmp[i] - 'A'] += 1;
	}
	for (int i = 0; i < 26; i++)
	{
		if (Max < check[i])
		{
			Max = check[i];
			idx = i;
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (idx==i)
		{
			continue;
		}
		if (Max == check[i])
		{
			cout << "?";
			return 0;
		}
	}
	cout << (char)(idx+65);

	return 0;
}
