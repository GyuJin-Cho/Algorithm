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

int main()
{
	int E, S, M;
	cin >> E >> S >> M;
	int cnt = 1;
	int ET = 1, ES = 1, EM = 1;
	while (1)
	{
		if (ET == E && ES == S && EM == M)
		{
			cout << cnt;
			break;
		}
		ET++;
		ES++;
		EM++;
		cnt++;

		if (ET > 15)
		{
			ET = 1;
		}
		if (ES > 28)
		{
			ES = 1;
		}
		if (EM > 19)
		{
			EM = 1;
		}
	}

	return 0;
}