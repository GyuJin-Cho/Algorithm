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
int d[21][21][21];
int DP(int a,int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	else if (a > 20 || b > 20 || c > 20)
		return DP(20, 20, 20);
	else if (d[a][b][c] != 0)
		return d[a][b][c];
	else if (a < b && b < c)
		d[a][b][c] = DP(a, b, c - 1) + DP(a, b - 1, c - 1) - DP(a, b - 1, c);
	else
		d[a][b][c] = DP(a - 1, b, c) + DP(a - 1, b - 1, c) + DP(a - 1, b, c - 1) - DP(a - 1, b - 1, c - 1);
	return d[a][b][c];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a, b, c;
	while(1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		cout<<"w("<<a<<", "<<b<<", "<<c<<") = " << DP(a, b, c) << '\n';
	}

	return 0;
}