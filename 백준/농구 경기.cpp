#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	map<char, int> m;
	string s;
	for(int i=0;i<N;i++)
	{
		cin >> s;
		m[s[0]]++;
	}
	string answer;
	for (auto i : m)
	{
		if(i.second>=5)
		{
			answer += i.first;
		}
	}
	if (answer.size() == 0)
		cout << "PREDAJA";
	else
		cout << answer;
	return 0;
}