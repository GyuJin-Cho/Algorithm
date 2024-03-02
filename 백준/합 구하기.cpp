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
	int sum[100001];
	int num, N, M;
	sum[0] = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}
	cin >> M;
	int s, e;
	while (M--)
	{
		cin >> s >> e;
		cout << sum[e] - sum[s - 1]<<'\n';
	}

	return 0;
}