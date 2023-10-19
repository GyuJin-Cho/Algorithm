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

bool check(const vector<int> &v , const vector<char> &c)
{
	for(int i=0;i<c.size();i++)
	{
		if (c[i] == '<' && v[i] > v[i + 1])
			return false;
		else if (c[i] == '>' && v[i] < v[i + 1])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<char> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];

	vector<int> small(n + 1);
	vector<int> big(n + 1);
	for(int i=0;i<=n;i++)
	{
		small[i] = i;
		big[i] = 9 - i;
	}

	do
	{
		if (check(big, c))
		{
			for (int i : big)
				cout << i;
			break;
		}
	} while (prev_permutation(big.begin(), big.end()));

	cout << '\n';

	do
	{
		if(check(small,c))
		{
			for (int i : small)
				cout << i;
			break;
		}
	} while (next_permutation(small.begin(), small.end()));
	
	return 0;
}