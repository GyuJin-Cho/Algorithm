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
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> d(n, -1);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	d[0] = 0;
	for(int i=0;i<n-1;i++)
	{
		if(d[i]==-1)
			continue;
		for(int j=1;j<=v[i];j++)
		{
			if (i + j >= n)
				break;
			if(d[i+j]==-1||d[i+1]>d[i]+1)
			{
				d[i + j] = d[i] + 1;
			}
		}
	}
	cout << d[n - 1];
	return 0;
}