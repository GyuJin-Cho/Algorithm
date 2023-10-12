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
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);
	for (int i = 2; i <= n; i++)
		v[i] = i;
	int cnt = 0;
	for(int i=2;i<=n;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			if(v[j]!=0)
			{
				v[j] = 0;
				cnt++;
				if(cnt==k)
				{
					cout << j;
					return 0;
				}
			}
		}
	}

	return 0;
}