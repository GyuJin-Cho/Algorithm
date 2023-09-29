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
	int n;
	cin >> n;
	int answer = 0;
	int len = 0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		int cnt = 0;
		while(x>0)
		{
			cnt += 1;
			answer += x % 2;
			x /= 2;
		}
		len = max(len, cnt);
	}
	answer += len - 1;
	if (answer < 0)
		answer = 0;
	cout << answer;
	return 0;
}