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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	map<string, int>m;
	for(int i=0;i<n;i++)
	{
		string str,tmp;
		cin >> str;
		size_t size = str.find(".");
		for(int j=size+1;j<str.length();j++)
		{
			tmp += str[j];
		}
		m[tmp]++;
	}
	for(const auto& i : m)
	{
		cout << i.first << ' ' << i.second<<'\n';
	}
	return 0;
}