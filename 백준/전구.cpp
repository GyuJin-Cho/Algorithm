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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	for(int i=0;i<m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 1)
		{
			v[b-1] = c;
		}
		else if(a == 2)
		{
			for(int j=b-1;j<c;j++)
			{
				if (v[j] == 1)
					v[j] = 0;
				else
					v[j] = 1;
			}
		}
		else if (a == 3)
		{
			for (int j = b - 1; j < c; j++)
			{
				v[j] = 0;
			}
		}
		else if (a == 4)
		{
			for (int j = b - 1; j < c; j++)
			{
				v[j] = 1;
			}
		}
	}

	for (int i : v)
		cout << i << ' ';

	return 0;
}