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
	set<int> A;
	set<int> B;

	int n, m,num;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		A.insert(num);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		B.insert(num);
	}
	vector<int> ans;
	for(int a : A)
	{
		if(B.find(a)==B.end())
		{
			ans.push_back(a);
		}
	}
	cout << ans.size()<<'\n';
	for (int i : ans)
		cout << i << ' ';
	return 0;
}