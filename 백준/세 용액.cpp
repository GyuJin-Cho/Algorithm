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
long long arr[5001];
long long ans[3];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	long long result = 1e12;
	for(int k=0;k<n-2;k++)
	{
		int s = k + 1, e = n - 1;
		while(s<e)
		{
			long long val = arr[k] + arr[s] + arr[e];
			if(abs(val)<result)
			{
				result = abs(val);
				ans[0] = arr[k];
				ans[1] = arr[s];
				ans[2] = arr[e];
			}
			if (val < 0)
				s++;
			else
				e--;
		}
	}
	for (int i = 0; i < 3; i++)
		cout << ans[i] << ' ';
	return 0;
}