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
	vector<int> v(n);
	unordered_map<int, int>um;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int start = 0, end = 1;
	um[v[start]]++;
	int Max = 1;
	while(end!=n)
	{
		um[v[end]]++;
		if(um[v[end]]>k)
		{
			if (Max < end - start)
				Max = end - start;
			while(um[v[end]]!=k)
			{
				um[v[start]]--;
				start++;
			}
		}
		end++;
	}

	if (Max < end - start)
		Max = end - start;

	cout << Max;

	return 0;
}