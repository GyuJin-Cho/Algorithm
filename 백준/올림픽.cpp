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

class Medal
{
public:
	int Gold;
	int Silver;
	int Bronze;
public:
	Medal() : Gold(0), Silver(0), Bronze(0) {}
	Medal(int g, int s, int b) : Gold(g), Silver(s), Bronze(b) {}
};

bool cmp(pair<int, Medal> m1, pair<int, Medal> m2)
{
	if (m1.second.Gold == m2.second.Gold)
	{
		if (m1.second.Silver == m2.second.Silver)
		{
			return m1.second.Bronze > m2.second.Bronze;
		}
		return m1.second.Silver > m2.second.Silver;
	}
	return m1.second.Gold > m2.second.Gold;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<pair<int, Medal>> country;
	for (int i = 0; i < n; i++)
	{
		int num, g, s, b;
		cin >> num >> g >> s >> b;
		country.push_back(make_pair(num, Medal(g, s, b)));
	}

	sort(country.begin(), country.end(), cmp);
	int number;
	for (int i = 0; i < country.size(); i++)
	{
		if (country[i].first == k)
		{
			number = i;
		}
	}
	int ans = 0;
	for (int i = number - 1; i >= 0; i--)
	{
		if (country[i].second.Gold != country[number].second.Gold || country[i].second.Silver != country[number].second.Silver ||
			country[i].second.Bronze != country[number].second.Bronze)
		{
			break;
		}
		ans++;
	}
	cout << number - ans + 1;
	return 0;
}