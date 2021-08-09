#include<iostream>

using namespace std;

int main()
{
	string answer;
	cin >> answer;
	bool check = false;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < answer.length(); j++)
		{
			check = false;
			if (answer[j] == 'a' + i)
			{
				cout << j << " ";
				break;
			}
			check = true;
		}
		if(check)
			cout << -1 << " ";
		check = false;
	}
	return 0;
}