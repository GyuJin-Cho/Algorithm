#include<iostream>
#include<string>

using namespace std;
string s[12] = { "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve" };
string s1[30] = { "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourtenn","quarter"
					,"sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three", "twenty four","twenty five","twenty six"
					,"twenty seven","twenty eight","twenty nine","half"};
int main()
{
	int h;
	string m;
	cin >> h >> m;
	if(stoi(m)==0)
	{
		cout << s[h - 1] << " o' clock";
	}
	else if(stoi(m)>=1&&stoi(m)<=30)
	{
		for(int i=1;i<=30;i++)
		{
			if (i == stoi(m))
			{
				if(i==1)
				{
					cout << s1[i - 1] << " minute past " << s[h - 1];
					break;
				}
				if (i == 15 || i == 30)
				{
					cout << s1[i - 1] << " past " << s[h - 1];
					break;
				}
				cout << s1[i - 1] << " minutes past " << s[h - 1];
				break;
			}
		}
	}
	else if(stoi(m)>30)
	{
		for (int i = 30; i < 59; i++)
		{
			if (i == stoi(m))
			{
				if (i == 45)
				{
					cout << s1[60-i - 1] << " to " << s[h];
					break;
				}
				cout << s1[60-i - 1] << " minutes to " << s[h];
				break;
			}
		}
	}
	return 0;
}