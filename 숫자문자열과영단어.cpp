#include <iostream>
#include <string>
#include <vector>

using namespace std;

long solution(string s)
{
	int answer = 0;
	string tmp;
	string check;
	for (int i = 0; i < s.length(); i++)
	{
		//if (s[i] == '0'||s[i] == '1' || s[i] == '2'||s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
		//{
		//	tmp += s[i];
		//}
		if (s[i] >= '0'&&s[i] <= '9')
		{
			tmp += s[i];
		}
		else
		{
			check += s[i];
			if (check == "zero")
			{
				tmp += '0';
				check = "";
			}
				
			else if (check == "one")
			{
				tmp += '1';
				check = "";
			}
				
			else if (check == "two")
			{
				tmp += '2';
				check = "";
			}
				
			else if (check == "three")
			{
				tmp += '3';
				check = "";
			}
				
			else if (check == "four")
			{
				tmp += '4';
				check = "";
			}

			else if (check == "five")
			{
				tmp += '5';
				check = "";
			}

			else if (check == "six")
			{
				tmp += '6';
				check = "";
			}

			else if (check == "seven")
			{
				tmp += '7';
				check = "";
			}

			else if (check == "eight")
			{
				tmp += '8';
				check = "";
			}

			else if (check == "nine")
			{
				tmp += '9';
				check = "";
			}
		}
	}
	answer = stoi(tmp);
	return answer;
}

int main()
{
	string s="one4seveneight";

	cout << solution(s);
	system("Pause");
	return 0;
}