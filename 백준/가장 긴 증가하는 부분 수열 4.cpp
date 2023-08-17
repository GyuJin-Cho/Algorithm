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
void DFS(int p, vector<int>&v, vector<int>&a)
{
	
	if (p == -1) {
		return;
	}
	DFS(v[p],v,a);
	cout << a[p] << ' ';
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> d(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		v[i] = -1;
		for (int j = 0; j < i; j++)
		{
			if (a[j]<a[i] && d[j] + 1>d[i])
			{
				d[i] = d[j] + 1;
				v[i] = j;
			}
		}
	}
	int answer = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		if (answer < d[i])
		{
			answer = d[i];
			p = i;
		}
	}
	cout << answer << '\n';
	DFS(p, v, a);
	return 0;
}