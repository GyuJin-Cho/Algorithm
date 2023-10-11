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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> alba(n+1);
	for(int i=0;i<n;i++)
	{
		cin >> alba[i];
	}
	long long answer = 0;
	long long sum = 0;
	for(int i=0;i<n;i++)
	{
		if(i>m-1)
		{
			sum -= alba[i - m];
		}
		sum += alba[i];
		answer = max(answer, sum);
	}
	cout << answer;
	return 0;
}