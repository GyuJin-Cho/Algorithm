#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n+1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> d(n+1);
	for (int i = 0; i < n; i++)
	{
		d[i] = a[i];
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && d[i] < d[j] + a[i])
			{
				d[i] = d[j] + a[i];
			}
		}
	}

	cout << *max_element(d.begin(), d.end());

	return 0;
}