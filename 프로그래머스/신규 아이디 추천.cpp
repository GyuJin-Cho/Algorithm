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
//  2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
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
//  3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
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
//  4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
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
//  5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
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
//  6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
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
//  7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
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