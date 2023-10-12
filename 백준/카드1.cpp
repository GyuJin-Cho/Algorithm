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
	for (int i = 0; i < n; i++)
		v[i] = i + 1;

	vector<int> s1;
	bool flag = false;
	while (v.size()!=1)
	{
		if(!flag)
		{
			s1.push_back(v[0]);
			v.erase(v.begin());
			flag = true;
		}
		else
		{
			v.push_back(v[0]);
			v.erase(v.begin());
			flag = false;
		}
	}
	s1.push_back(v[0]);
	for (int i : s1)
		cout << i << ' ';
	return 0;
}