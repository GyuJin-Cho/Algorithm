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
	unsigned long long num;
	cin >> n;
	map<long long, int> m;
	while(n--)
	{
		cin >> num;
		m[num]++;
	}

	long long ans = 0;
	int tmp = -217400000;

	for(auto & i : m)
	{
		if(i.second>tmp)
		{
			tmp = i.second;
			ans = i.first;
		}
	}
	cout << ans;
	return 0;
}