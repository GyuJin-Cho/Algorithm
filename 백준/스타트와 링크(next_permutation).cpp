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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> a[i][j];
		}
	}

	vector<int> b(n);
	for(int i=0;i<n/2;i++)
	{
		b[i] = 1;
	}
	sort(b.begin(), b.end());
	int answer = 217400000;
	do
	{
		vector<int> first, second;
		for(int i=0;i<n;i++)
		{
			if(b[i]==0)
			{
				first.push_back(i);
			}
			else
			{
				second.push_back(i);
			}
		}
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j)
					continue;
				one += a[first[i]][first[j]];
				two += a[second[i]][second[j]];
			}
		}
		int diff = one - two;
		if (diff < 0)
			diff = -diff;
		if (answer > diff)
			answer = diff;
	} while (next_permutation(b.begin(), b.end()));
	cout << answer;
	return 0;
}