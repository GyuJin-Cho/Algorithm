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

bool check(const vector<int> &perm, const vector<char> &a)
{
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='<'&&perm[i]>perm[i+1])
			return false;
		if(a[i]=='>'&&perm[i]<perm[i+1])
			return false;
		
	}
	return true;
}

int main()
{
	int k;
	cin >> k;
	vector<char> a(k);
	for(int i=0;i<k;i++)
	{
		cin >> a[i];
	}
	vector<int> small(k + 1);
	vector<int> big(k + 1);
	for(int i=0;i<=k;i++)
	{
		small[i] = i;
		big[i] = 9 - i;
	}
	do
	{
		if (check(small, a))
			break;
	} while (next_permutation(small.begin(), small.end()));

	do
	{
		if (check(big, a))
			break;
	} while (prev_permutation(big.begin(), big.end()));
	for(int i=0;i<big.size();i++)
	{
		cout << big[i];
	}
	cout << '\n';
	for(int i=0;i<small.size();i++)
	{
		cout << small[i];
	}
	return 0;
}