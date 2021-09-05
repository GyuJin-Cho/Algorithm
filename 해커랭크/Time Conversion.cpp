#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	string h = s.substr(0,2);
	string m = s.substr(3, 2);
	string sec = s.substr(6, 2);
	if (s.find("PM") == string::npos)
	{
		if (h == "12")
		{
			cout << "00" << ":" << m << ":" << sec << endl;
		}
		else
		{
			cout << h << ":" << m << ":" << sec << endl;
		}
	}
	else
	{
		if (h == "12")
		{
			cout << h << ":" << m << ":" << sec << endl;
		}
		else
		{
			cout << stoi(h) + 12 << ":" << m << ":" << sec << endl;
		}
	}
		cout << stoi(h) + 12 << ":" << m << ":" << sec << endl;
	return 0;
}