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
int n, t, ans;
int choose[100010];
bool visited[100010];
bool done[100010];

void DFS(int Depth)
{
	visited[Depth] = true;

	int nx = choose[Depth];

	if (!visited[nx])
		DFS(nx);
	else if(!done[nx])
	{
		for(int i=nx;i!=Depth;i=choose[i])
		{
			ans++;
		}
		ans++;
	}
	done[Depth] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 0;

		for(int i=1;i<=n;i++)
		{
			cin >> choose[i];
			visited[i] = false;
			done[i] = false;
		}

		for(int i=1;i<=n;i++)
		{
			if (!visited[i])
				DFS(i);
		}
		cout << n - ans << '\n';
	}

	return 0;
}