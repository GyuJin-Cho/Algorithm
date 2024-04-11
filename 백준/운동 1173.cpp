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
	int N, m, M, T, R;
	cin >> N >> m >> M >> T >> R;
	if (m + T > M)
	{
		cout << -1;
		return 0;
	}
	int cnt = 0;
	int ans = 0;
	int basepulse = m;
	while (cnt < N)
	{
		ans++;
		if (basepulse + T <= M)
		{
			basepulse += T;
			cnt++;
		}
		else
		{
			basepulse = max(m, basepulse - R);
		}
	}

	cout << ans;

	return 0;
}