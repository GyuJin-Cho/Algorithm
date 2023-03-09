#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	string s, search;
	cin >> s;
	cin >> search;
	if (strstr((char*)s.c_str(), (char*)search.c_str()) == NULL)
		cout << 0;
	else
		cout << 1;
	
	return 0;
}