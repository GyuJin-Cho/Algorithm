#include<iostream>
#include<map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		int answer = 1;
		map<string, int> m;
		for (int j = 0; j < a; j++)
		{
			string type;
			string name;
			cin >> type >> name;
			m[name] += 1;
		}
		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			answer = answer * (iter->second + 1);
		}
		answer -= 1;
		cout << answer << endl;
	}

	return 0;
}