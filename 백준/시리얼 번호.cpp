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

bool cmp(string s1, string s2)
{
	if(s1.length()==s2.length())
	{
		int sum1 = 0, sum2 = 0;
		for(int i=0;i<s1.length();i++)
		{
			if(s1[i]>='0'&&s1[i]<='9')
			{
				sum1 += (s1[i] - 48);
			}
			if (s2[i] >= '0' && s2[i] <= '9')
			{
				sum2 += (s2[i] - 48);
			}
		}
		if(sum1==sum2)
		{
			return s1 < s2;
		}
		return sum1 < sum2;
	}

	return s1.length() < s2.length();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	sort(v.begin(), v.end(), cmp);

	for (string& s : v)
		cout << s << '\n';
	return 0;
}