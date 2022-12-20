#include<iostream>
#include <string>
#include <string.h>
using namespace std;


int recursion(const char* s, int l, int r, int& cnt)
{
	cnt++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1,cnt);
}


int isPalindrome(const char* str, int& cnt)
{
	return recursion(str, 0, strlen(str) - 1,cnt);
}

int main()
{
	int n;
	cin >> n;
	char str[1001]="";
	int cnt;
	for(int i=0;i<n;i++)
	{
		cnt = 0;
		cin >> str;
		cout << isPalindrome(str,cnt) << " ";
		cout <<cnt<<endl;
	}

	return 0;
}