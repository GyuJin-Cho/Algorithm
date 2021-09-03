#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque<int> de;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string a;
		int c;
		cin >> a;
		if (a == "push_back")
		{
			cin >> c;
			de.push_back(c);
		}
		else if (a == "push_front")
		{
			cin >> c;
			de.push_front(c);
		}
		else if (a == "pop_front")
		{
			if (de.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.front() << endl;
				de.pop_front();
			}
		}
		else if (a == "pop_back")
		{
			if (de.size() == 0)
			{
				cout << -1<<endl;
			}
			else
			{
				cout << de.back() << endl;
				de.pop_back();
			}
		}
		else if (a == "size")
		{
			cout << de.size() << endl;
		}
		else if (a == "empty")
		{
			if (de.size() == 0)
			{
				cout << 1 << endl;
			}
			else
			{
				cout << 0 << endl;
			}
		}
		else if (a == "front")
		{
			if (de.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.front() << endl;
			}
		}
		else if (a == "back")
		{
			if (de.size() == 0)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << de.back() << endl;
			}
		}
	}
	return 0;
}