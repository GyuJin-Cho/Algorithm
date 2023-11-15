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
	int T;
	cin >> T;
	
	while(T--)
	{
		int n, m;
		cin >> n >> m;
		vector<int> v1(n);
		vector<int> v2(m);
		for (int i = 0; i < n; i++)
			cin >> v1[i];
		for (int i = 0; i < m; i++)
			cin >> v2[i];

		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int ans = 0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if (v1[i] > v2[j])
					ans++;
				else
					break;
			}
		}
		cout << ans<<'\n';
	}

	return 0;
}