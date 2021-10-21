#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int answer = 0;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i; j >= 0; j--)
		{
			answer += v[j];
		}
	}
	cout << answer << endl;
	return 0;
}