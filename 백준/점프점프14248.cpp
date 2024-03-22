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
#define MAX 100002
int arr[MAX];
bool visited[MAX];
int n;

void DFS(int start)
{
	if (start <= 0 || start > n)
		return;
	visited[start] = true;
	DFS(start + arr[start]);
	DFS(start - arr[start]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	int start;
	cin >> start;
	DFS(start);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i])
			ans++;
	}
	cout << ans;
	return 0;
}