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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}
	int s = 0;
	int e = 1;
	long long ans = 0;
	map<int, bool>m;
	m[v[s]] = true;
	while(s<e&&v.size()>e)
	{
		if(m[v[e]]==true)
		{
			m.erase(v[s]);
			s++;
		}
		if(!m[v[e]]&&v.size()>e)
		{
			m[v[e]] = true;
			ans += m.size();
			e++;
		}
	}
	
	cout << ans+1;
	return 0;
}