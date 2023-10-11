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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cout<<v[m - 1];
	return 0;
}