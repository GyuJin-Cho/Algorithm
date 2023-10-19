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
const int INF = 1e9;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> arr(n + 1);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int start = -1;
	int end = -1;
	int sum = 0;
	int length = INF;

	while(end<n&&start<=n)
	{
		if(sum<m)
		{
			end++;
			sum += arr[end];
		}
		else if(sum>=m)
		{
			if(length>(end-start))
			{
				length = end - start;
			}
			start++;
			sum -= arr[start];
		}
	}
	if (length == INF)
		cout << 0;
	else
		cout << length;
	return 0;
}