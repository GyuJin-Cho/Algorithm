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
int n, s;
int answer = 0;
void DFS(int idx, vector<int>& nums, int sum)
{

	if (idx == n)
		return;
	if (sum + nums[idx]==s)
	{
		answer++;
		return;
	}
	DFS(idx + 1, nums, sum);
	DFS(idx + 1, nums, sum + nums[idx]);
}

int main()
{
	cin >> n >> s;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}

	DFS(0, nums,0);
	cout << answer;
	return 0;
}