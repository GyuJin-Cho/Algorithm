#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<string, int> m;
	int n, k;
	cin >> n >> k;

	string str;
	for(int i=0;i<n;i++)
	{
		cin >> str;
		m[str]++;
	}
	int cnt = 0;
	for(int j=0;j<k;j++)
	{
		cin >> str;
		if (m[str] > 0)
			cnt++;
	}

	cout << cnt;

	return 0;
}