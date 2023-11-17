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
	unordered_map<string,int> um;
	int n, m;
	string num;
	cin >> n >> m;

	for(int i=0;i<m;i++)
	{
		cin >> num;
		if(um.find(num)!=um.end())
		{
			unordered_map<string, int>::iterator iter = um.find(num);
			um.erase(iter);
			um[num] = i;
		}
		else
		{
			um[num] = i;
		}
	}
	int j = 0;
	vector<pair<int, string>> ans;
	for (auto& i : um)
	{
		ans.push_back({ i.second, i.first });
	}
	sort(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++)
	{
		if (i == n)
			break;
		cout << ans[i].second << '\n';
	}
	return 0;
}