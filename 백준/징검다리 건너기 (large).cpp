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
constexpr int MAX = 5001;
int n;
long long arr[MAX], DP[MAX];

long long GO(int num)
{
	if (num == n - 1)
		return 0;
	long long& ref = DP[num];
	if (ref != -1)
		return ref;

	ref = 1e10;

	for (int i = num + 1; i < n; i++)
		ref = min(ref, max(GO(i), (i - num) * (1 + abs(arr[num] - arr[i]))));
	return ref;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	memset(DP, -1, sizeof(DP));
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cout << GO(0);
	return 0;
}