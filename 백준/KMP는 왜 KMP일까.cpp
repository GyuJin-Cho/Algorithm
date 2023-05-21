#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string answer = "";
	for(int i=0;i<s.size();i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			answer += s[i];
	}
	cout << answer;
	return 0;
}