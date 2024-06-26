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
int n;

bool IsPrime(int s)
{
	for (int i = 2; i <= s / 2; i++)
	{
		if (s % i == 0)
		{
			return false;
		}
	}
	return true;
	
}

void DFS(int s, int idx)
{
	if (n == idx)
	{
		if (IsPrime(s))
		{
			cout << s << '\n';
			return;
		}
	}
	for (int i = 1; i < 10; i++)
	{
		if (i % 2 == 0)
			continue;
		if (IsPrime(s * 10 + i))
		{
			DFS(s * 10 + i, idx + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	DFS(2, 1);
	DFS(3, 1);
	DFS(5, 1);
	DFS(7, 1);

	return 0;
}