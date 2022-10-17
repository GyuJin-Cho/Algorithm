#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n+m);
	for (int i = 0; i < n+m; i++)
	{
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] <<" ";
	}

	return 0;
}