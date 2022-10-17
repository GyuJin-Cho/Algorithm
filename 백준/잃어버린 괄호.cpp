#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int answer = 0;
	bool MinusCheck = false;
	string temp;
	for (int i = 0; i <= s.size(); i++)
	{
		if (s[i] == '+'||s[i]=='-'||i==s.size())
		{
			if (MinusCheck)
			{
				answer -= stoi(temp);
			}
			else if (s[i] == '-')
			{
				MinusCheck = true;
				answer += stoi(temp);
			}
			else
			{
				answer += stoi(temp);
			}
			temp = "";
		}
		else
		{
			temp += s[i];
		}
		
	}
	cout << answer;
	return 0;
}