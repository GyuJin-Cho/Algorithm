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
	map<string, int> m;
	string s;
	float cnt = 0;
	while(getline(cin,s))
	{
		m[s]++;
		cnt++;
	}

	for(auto i : m)
	{
		cout << i.first;
		printf(" %.4f\n", (i.second * 100.0f / cnt));
	}

	return 0;
}