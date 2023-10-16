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
#include<cstring>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	bool ch = false;
	bool cycle = false;
	do
	{
		if(cycle)
		{
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i] << ' ';
				ch = true;
			}
			if (ch)
				break;
		}
		cycle = true;
	} while (next_permutation(v.begin(), v.end()));
	if (!ch)
		cout << -1;
	return 0;
}