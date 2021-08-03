#include<iostream>

using namespace std;

int main()
{
	int count = 0;

	int answer=0;

	string n;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> n;
		for (int j = 0; j < n.length(); j++)
		{
			if (n[j] == 'O')
			{
				count++;
				answer += count;
			}
			else
			{
				count = 0;
			}
		}
		cout << answer << endl;
		count = 0;
		answer = 0;
	}
}