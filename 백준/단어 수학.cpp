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
char alpha[256];

int calc(const vector<string>&a, const vector<char> &letters, const vector<int> &d)
{
	int m = letters.size();
	int sum = 0;
	for(int i=0;i<m;i++)
	{
		alpha[letters[i]] = d[i];
	}
	for(string s : a)
	{
		int now = 0;
		for(char x: s)
		{
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<string>a(n);
	vector<char> letters;
	for(int i=0; i<n; i++)
	{
		cin >> a[i];
		for(char x : a[i])
		{
			letters.push_back(x);
		}
	}

	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
	int m = letters.size();
	vector<int> d;
	for (int i = 9; i > 9 - m; i--)
		d.push_back(i);
	sort(d.begin(), d.end());
	int ans = 0;
	do
	{
		int now = calc(a, letters, d);
		if (ans < now)
			ans = now;
	} while (next_permutation(d.begin(), d.end()));
	cout << ans;
	return 0;
}