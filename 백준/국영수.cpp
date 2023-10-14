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

bool cmp(tuple<string,int,int,int> t1, tuple<string,int,int,int> t2)
{
	if(get<1>(t1)==get<1>(t2))
	{
		if(get<2>(t1)==get<2>(t2))
		{
			if(get<3>(t1)==get<3>(t2))
			{
				return get<0>(t1) < get<0>(t2);
			}
			return get<3>(t1) > get<3>(t2);
		}
		return get<2>(t1) < get<2>(t2);
	}
	return get<1>(t1) > get<1>(t2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<tuple<string, int, int, int>> v;
	int n;
	cin >> n;

	while (n--)
	{
		string s;
		int korean, english, math;
		cin >> s >> korean >> english >> math;
		v.push_back(make_tuple(s, korean, english, math));
	}

	sort(v.begin(), v.end(), cmp);
	for(auto i : v)
	{
		cout << get<0>(i)<<'\n';
	}
	return 0;
}