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
	string s;
	cin >> n;
	map<string, int> um;
	while(n--)
	{
		cin >> s;
		um[s]++;
	}

	string answer;
	int maxnum=-2174000;
	for(auto i : um)
	{
		if(i.second>maxnum)
		{
			answer = i.first;
			maxnum = i.second;
		}
		/*else if(i.second==maxnum)
		{
			if(answer>i.first)
			{
				answer = i.first;
			}
		}*/
	}
	cout << answer;
	return 0;
}