#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Medal
{
public:
	int Gold;
	int Silver;
	int Bronze;
public:
	Medal() : Gold(0), Silver(0), Bronze(0){}
	Medal(int g,int s, int b) : Gold(g), Silver(s), Bronze(b){}
	
};

bool cmp(pair<int,Medal> m1, pair<int,Medal> m2)
{
	if(m1.second.Gold==m2.second.Gold)
	{
		if(m1.second.Silver==m2.second.Silver)
		{
			return m1.second.Bronze > m2.second.Bronze;
		}
		return m1.second.Silver > m2.second.Silver;
	}
	return m1.second.Gold > m2.second.Gold;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<pair<int, Medal>> country(N);

	for(int i=0;i<N;i++)
	{
		int num,g,s,b;
		cin >> num >> g >> s >> b;
		country[i] = make_pair(num, Medal(g,s,b));
	}

	sort(country.begin(), country.end(),cmp);
	int result;
	for(int i=0;i<country.size();i++)
	{
		if(country[i].first==K)
		{
			result = i;
		}
	}
	int ans = 0;
	for(int i=result-1;;i--)
	{
		if(country[i].second.Gold!=country[result].second.Gold||country[i].second.Silver!=country[result].second.Silver||
			country[i].second.Bronze!=country[result].second.Bronze)
		{
			break;
		}
		ans++;
	}
	cout << result - ans + 1;
	return 0;
}