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
#define MAX 217400000
int main()
{
	int N;
	cin >> N;
	int T, BT;
	int ans = MAX;
	while(N--)
	{
		cin >> T >> BT;
		if(T>BT)
			continue;
		ans = min(ans, (T)+(BT - T));
	}
	if (MAX == ans)
		cout << -1;
	else
		cout << ans;

	return 0;
}