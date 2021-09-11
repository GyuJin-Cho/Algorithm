#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main()
{
	vector<pair<long long, int>> v;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		long long c;
		cin >> c;
		v.push_back({ c, i });
	}
	long long Min = 10000000000000;
	sort(v.begin(), v.end());
	for(int i=1;i<n;i++)
	{
		if(v[i].second<v[i-1].second)
		{
			Min = min(Min, abs(v[i].first - v[i - 1].first));
		}
	}
	cout << Min;
}
