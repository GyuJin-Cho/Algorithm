#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string N;
	while (true)
	{
		cin >> N;
		string tmp = N;
		reverse(N.begin(), N.end());
		if (N == "0")
			break;
		else if (N != "0")
		{
			if (N == tmp)
			{
				cout << "yes\n";
			}
			else
			{
				cout << "no\n";
			}	
		}
		
	}
	return 0;
}
