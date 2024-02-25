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
	int N;
	while (1)
	{
		cin >> N;
		if (N == -1)
			break;
		int ans = 0;
		
		for (int i = 2; i <= N; i++)
		{
			int tmp = N;
			bool ch = false;
			int checkans = 0;
			while (tmp != 0)
			{
				
				if (checkans == i)
					break;
				if ((tmp - 1) % i != 0)
				{
					ch = true;
					break;
				}
				else
				{
					int div = (tmp - 1) / i;
					tmp = tmp - 1 - div;
				}
				checkans++;
			}
			if (!ch)
				ans = max(ans, i);
		}

		if (ans == 0)
			cout << N << " coconuts, no solution" << '\n';
		else
			cout << N << " coconuts, " << ans << " people and 1 monkey" << '\n';
	}
}