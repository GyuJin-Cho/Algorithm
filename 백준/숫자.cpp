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
	unsigned long long n, m;
	cin >> n >> m;
	if(n>m)
	{
		swap(n, m);
	}
	vector<unsigned long long> v;
	for(unsigned long long i=n+1;i<m;i++)
	{
		v.push_back(i);
	}
	cout << v.size()<<'\n';
	for (unsigned long long i : v)
		cout << i << ' ';
	return 0;
}