#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int n,k;
	cin >> n>>k;
	v.resize(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cout << v[v.size()-k];

	return 0;
}