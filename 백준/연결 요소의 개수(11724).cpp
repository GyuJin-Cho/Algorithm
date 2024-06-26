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
constexpr int MAX = (1001 * (1001 - 1) / 2);
vector<int> arr[MAX];

bool visit[MAX];

void DFS(int num)
{
	visit[num] = true;
	for (int i = 0; i < arr[num].size(); i++)
	{
		if (!visit[arr[num][i]])
		{
			DFS(arr[num][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int x, y;
	int ans = 0;
	cin >> n >> m;
	if (m == 0)
	{
		cout << n;
		return 0;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!visit[i])
		{
			DFS(i);
			ans++;
		}
	}
	cout << ans;
	return 0;
}