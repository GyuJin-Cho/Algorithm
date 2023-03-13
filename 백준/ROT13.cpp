#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string answer="";
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='a'&&s[i]<='z')
		{
			if(s[i]-'a'<13)
			{
				char c = s[i]+13;
				
				answer += c;
				continue;
			}
			else if(s[i]-'a'>13)
			{

				char c = s[i] - 13;

				answer += c;
				continue;
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			if (s[i] - 'A' < 13)
			{
				char c = s[i] + 13;

				answer += c;
				continue;
			}
			else if (s[i] - 'A' > 13)
			{

				char c = s[i] - 13;

				answer += c;
				continue;
			}
		}
		answer += s[i];
	}
	cout << answer<<'\n';
	return 0;
}