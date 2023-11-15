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

string video[64];
void DivideConquer(int n, int y, int x)
{
	char cur = video[y][x];

	for(int i=y;i<y+n;i++)
	{
		for(int j=x;j<x+n;j++)
		{
			if(video[i][j]!=cur)
			{
				cout << '(';
				DivideConquer(n / 2, y, x);
				DivideConquer(n / 2, y, x + n / 2);
				DivideConquer(n / 2, y + n / 2, x);
				DivideConquer(n / 2, y + n / 2, x + n /2);
				cout << ')';
				return;
			}
		}
	}
	cout << cur;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> video[i];

	DivideConquer(n,0,0);
	return 0;
}
