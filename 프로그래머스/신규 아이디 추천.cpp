#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void Step1(char* string)
{
	for (unsigned int i = 0; i < strlen(string); i++)
	{
		string[i] = tolower(string[i]);

	}

}
//  2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
void Step2(char* string)
{

	for (unsigned int i = 0; i < strlen(string); i++)
	{
		if (isalpha(string[i]))
			continue;
		if (isdigit(string[i]))
			continue;
		if (string[i] == '-' || string[i] == '_' || string[i] == '.')
			continue;
		char* p = &string[i];
		memmove(p, p + 1, strlen(p + 1));
		string[strlen(string) - 1] = '\0';
		i--;
	}

}
//  3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
//  strchr, strrchr,strstr,strtok
void Step3(char* string)
{
	for (unsigned int i = 0; i < strlen(string); i++)
	{
		if (i == 0)
			continue;
		if (string[i] != '.')
			continue;
		if (string[i - 1] != '.')
			continue;

		char* p = &string[i];
		memmove(p, p + 1, strlen(p + 1));
		string[strlen(string) - 1] = '\0';
		i--;
	}
}
//  4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
void Step4(char* string)
{
	if (strlen(string) == 0)
		return;
	if (string[strlen(string) - 1] == '.')
		string[strlen(string) - 1] = '\0';
	if (string[0] == '.')
	{
		char* p = &string[0];
		memmove(p, p + 1, strlen(p + 1));
		string[strlen(string) - 1] = '\0';
	}
}
//  5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
void Step5(char* string)
{
	char  dummy[] = "a";
	if (strlen(string) != 0)
	{
		return;
	}
	memcpy(string, dummy, 1);
	string[1] = '\0';
}
//  6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
void Step6(char* string)
{
	if (strlen(string) >= 16)
	{
		for (int i = 15; i < strlen(string); i++)
		{
			string[i] = '\0';
		}
	}
	if (string[14] == '.')
		string[14] = '\0';
}
//  7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
void Step7(char* string)
{
	char dummy[] = "\0";

	if (strlen(string) == 1)
	{
		dummy[0] = string[0];
		dummy[1] = '\0';

		memcpy(&string[1], dummy, 1);
		memcpy(&string[2], dummy, 1);
		string[3] = '\0';
	}
	if (strlen(string) == 2)
	{
		dummy[0] = string[1];
		dummy[1] = '\0';

		memcpy(&string[2], dummy, 1);
		string[3] = '\0';
	}
}
string solution(string new_id) {
	char a[1002] = { '\0', };
	strcpy(a, new_id.c_str());
	Step1(a);
	Step2(a);
	Step3(a);
	Step4(a);
	Step5(a);
	Step6(a);
	Step7(a);
	string answer(a);

	return answer;
}

int main()
{
	cout << solution("...!@BaT#*..y.abcdefghijklm");

	return 0;
}