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

bool Check(const vector<int>& a, const int& l)
{

	int n = a.size();
	vector<bool> ch(n, false);
	for (int i = 1; i < n; i++)
	{
		if (a[i - 1] != a[i])
		{
			int dif = a[i] - a[i - 1];
			if (dif < 0)
				dif = -dif;
			if (dif != 1)
				return false;
			if (a[i - 1] < a[i])
			{
				for (int j = 1; j <= l; j++)
				{
					if (i - j < 0)
						return false;
					if (a[i - 1] != a[i - j])
						return false;
					if (ch[i - j])
						return false;
					ch[i-j] = true;
				}
			}
			else
			{
				for (int j = 0; j < l; j++)
				{
					if (i + j >= n)
						return false;
					if (a[i] != a[i + j])
						return false;
					if (ch[i + j])
						return false;
					ch[i + j] = true;
				}
				
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, l;
	cin >> n >> l;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> d;
		for (int j = 0; j < n; j++)
		{
			d.push_back(a[i][j]);
		}
		if (Check(d, l))
			answer++;
	}
	for (int i = 0; i < n; i++)
	{
		vector<int>d;
		for (int j = 0; j < n; j++)
		{
			d.push_back(a[j][i]);
		}
		if (Check(d, l))
			answer++;
	}
	cout << answer;
	return 0;
}