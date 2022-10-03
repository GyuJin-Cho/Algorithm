#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;
	vector<int> v(T);
	for (int i = 0; i < T; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (auto i : v)
	{
		cout << i << endl;
	}

	return 0;
}