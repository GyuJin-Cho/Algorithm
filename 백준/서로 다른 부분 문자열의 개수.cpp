#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	set<string> s;

	
	for(int i=0;i<str.size();i++)
	{
		string tmp = "";
		for(int j=i;j<str.size();j++)
		{
			tmp += str[j];
			s.insert(tmp);
		}
	}

	cout << s.size();
	return 0;
}