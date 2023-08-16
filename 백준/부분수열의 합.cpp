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
	int n,s;
	cin >> n >> s;
	int answer = 0;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for (int i = 1; i < (1 << n); i++)
	{
		int sum = 0;
		for (int k = 0; k < n; k++)
		{
			if (i & (1 << k))
			{
				sum += v[k];
			}
		}
		if (sum == s)
			answer++;
	}
	cout << answer;
	return 0;
}