#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cout << s.front() << s.back() << endl;;
	}
	

	return 0;
}