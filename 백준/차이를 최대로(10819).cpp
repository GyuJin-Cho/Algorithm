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
	for(int i=0;i<n;i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());
	int ans = -217400000;
	do
	{
		int sum = 0;
		for(int i=1;i<v.size();i++)
		{
			sum += (abs(v[i - 1] - v[i]));
		}
		ans = max(ans, sum);

	} while (next_permutation(v.begin(), v.end()));
	cout << ans;
	
	return 0;
}