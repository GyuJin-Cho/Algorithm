#include<iostream>
#include<string>

using namespace std;

int main()
{
	string a;
	int count = 1;
	getline(cin, a);
	if (a.empty())
	{
		cout << 0;
		return 0 ;
	}
		
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			count++;
		}
	}
	if (a[0] == ' ')
		count--;
	if (a[a.length() - 1] == ' ')
		count--;
	cout << count;
	return 0;
}