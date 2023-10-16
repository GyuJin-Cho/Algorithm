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
vector<int> v;
int n, s;
int ans = 0;
void DFS(int idx,int sum)
{
	if(idx>=n)
	{
		return;
	}
	if (sum + v[idx]==s)
	{
		ans++;
	}
	DFS(idx + 1, sum + v[idx]);
	DFS(idx + 1, sum);
}

int main()
{
	cin >> n >> s;
	int num;
	for(int i=0;i<n;i++)
	{
		cin >> num;
		v.push_back(num);
	}
	DFS(0, 0);

	cout << ans;
	
	return 0;
}