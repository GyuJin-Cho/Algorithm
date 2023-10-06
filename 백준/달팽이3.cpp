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
	long long n, m;
	cin >> n >> m;
	long long d = (min(n, m) - 1) / 2;
	long long answer = 4 * d;
	long long row = 1 + d;
	long long col = 1 + d;
	n -= 2 * d;
	m -= 2 * d;

	if (n == 1)
		col += (m - 1);
	else if(m==1)
	{
		answer += 1;
		row += (n - 1);
	}
	else if(n==2)
	{
		answer += 2;
		row += 1;
	}
	else
	{
		answer += 3;
		row += 1;
	}
	cout << answer << '\n';
	cout << row << ' ' << col;
	return 0;
}