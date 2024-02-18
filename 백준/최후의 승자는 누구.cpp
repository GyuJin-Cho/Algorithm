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
	int N, M;
	cin >> N >> M;
	int arr[101][101];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			cin >> arr[i][j];
		}
		sort(arr[i], arr[i] + M);
	}
	map<int, int>m;
	for(int i=0;i<M;i++)
	{
		vector<pair<int, int>> v;
		for(int j=0;j<N;j++)
		{
			v.push_back({ arr[j][i],j + 1 });
		}
		sort(v.begin(), v.end(),greater<>());
		int Max = v[0].first;
		m[v[0].second]++;
		for(int j=1;j<N;j++)
		{
			if (Max == v[j].first)
				m[v[j].second]++;
		}
	}
	vector<int> ans;
	int Max = -1e9;
	for(auto i : m)
	{
		if (i.second > Max)
		{
			ans.clear();
			Max = i.second;
			ans.push_back(i.first);
		}
		else if (i.second == Max)
			ans.push_back(i.first);
	}
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << ' ';
	return 0;
}