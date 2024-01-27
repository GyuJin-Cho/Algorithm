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
string tmp = "";
vector<string> v;
void zero()
{
	while (1)
	{
		if (tmp.size() && tmp.front() == '0')
		{
			tmp.erase(tmp.begin());
		}
		else
			break;
	}
	if (tmp.size() == 0)
		tmp = "0";
	v.push_back(tmp);
	tmp = "";
}

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	int N;
	cin >> N;
	string s;
	
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		tmp = "";
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] >= '0' && s[j] <= '9')
				tmp += s[j];
			else if (tmp.size())
				zero();
		}
		if (tmp.size())
			zero();
	}
	sort(v.begin(), v.end(),cmp);
	for (const auto& i : v)
		cout << i << '\n';
	return 0;
}