#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int solution(string str1, string str2)
{
	int answer = 0;
	if (str2.find(str1)==string::npos)
		return 0;
	else
		return 1;
	return answer;
}

int main()
{
	cout << solution("abc", "aabcc");
	
	return 0;
}