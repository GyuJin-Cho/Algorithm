#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<bool> BreakenButton(10, false);

bool check(int Button)
{
	string s = to_string(Button);
	for (int i = 0; i < s.size(); i++)
	{
		if (BreakenButton[s[i] - 48])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int Chanal = 0;
	cin >> Chanal;
	int breaken;
	cin >> breaken;
	
	for (int i = 0; i < breaken; i++)
	{
		int a;
		cin >> a;
		BreakenButton[a] = true;
	}


	int Min = abs(Chanal - 100);
	for (int i = 0; i <= 1000000; i++)
	{
		if (check(i))
		{
			int tmp = abs(Chanal - i) + to_string(i).size();
			Min = min(Min, tmp);
		}
	}

	cout << Min << endl;

	return 0;
}