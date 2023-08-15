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
int w[20][20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = i;
	}

	int answer = 21740000;

	do 
	{
		bool ch = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (w[d[i]][d[i + 1]] == 0)
			{
				ch = false;
			}
			else
			{
				sum += w[d[i]][d[i + 1]];
			}
		}
		if (ch && w[d[n - 1]][d[0]] != 0)
		{
			sum += w[d[n - 1]][d[0]];
			answer = min(answer, sum);
		}
	} while (next_permutation(d.begin(), d.end()));
	cout << answer;
	return 0;
}