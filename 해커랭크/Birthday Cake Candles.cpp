#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
	int T;
	cin >> T;
	vector<int> v;
	int count = 1;
	for (int i = 0; i < T; i++)
	{
		int a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i > 0; i--)
	{
		if (v[i] == v[i - 1] && i != -1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	cout << count;
	return 0;
}