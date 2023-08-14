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

using namespace std;
int t[21];
int p[21];
int n;
int answer = -217400000;

void DFS(int day, int sum)
{
	if (day == n + 1)
	{
		answer = max(sum, answer);
		return;
	}
	if (day > n + 1)
	{
		return;
	}
	DFS(day + 1, sum);
	DFS(day + t[day], sum + p[day]);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}
	DFS(1, 0);
	cout << answer;
}