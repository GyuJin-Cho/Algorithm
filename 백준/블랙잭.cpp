#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int max = 0;
	int tmp = 0;
	vector<int> a;
	int n, t,q;
	cin >> n>>t;
	for (int i = 0; i < n; i++)
	{
		cin >> q;
		a.push_back(q);
	}

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i+1; j < a.size(); j++)
		{
			for (int z = j+1; z < a.size(); z++)
			{
				tmp = a[i] + a[j] + a[z];
				if (tmp <= t && tmp > max)
				{
					max = tmp;
				}
			}
		}
	}
	cout << max;
	return 0;

}