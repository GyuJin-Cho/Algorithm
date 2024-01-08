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
	int n, k;
	cin >> n >> k;
	vector<int>  v(n + 1);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int s = 0, e = 0;
	int cnt = (v[s] & 1) ? 1 : 0;
	int m=-1e9;

	while(1)
	{
		while(e<n-1)
		{
			if(v[e+1]&1)
			{
				if (cnt < k)
					cnt++;
				else
					break;
			}
			e++;
		}
		
		if (s >= n || e >= n)
			break;
		m = max(m, e - s + 1 - cnt);
		if (v[s] & 1)
			cnt--;
		s++;
	}
	
	cout << m;
	return 0;
}