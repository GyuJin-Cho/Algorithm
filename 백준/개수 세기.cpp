#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int, int> m;
	int n;
	cin >> n;
	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		m[num]++;
	}

	int answer;
	cin >> answer;
	cout << m[answer];

	return 0;
}