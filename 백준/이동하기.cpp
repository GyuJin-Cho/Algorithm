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

int n, m;
int a[1001][1001];
int answer = 0;
int d[1001][1001];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

    d[1][1] = a[1][1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++) 
        {
            // 오른쪽
            if (j + 1 <= m && d[i][j + 1] < d[i][j] + a[i][j + 1])
            {
                d[i][j + 1] = d[i][j] + a[i][j + 1];
            }
            // 아래
            if (i + 1 <= n && d[i + 1][j] < d[i][j] + a[i + 1][j]) 
            {
                d[i + 1][j] = d[i][j] + a[i + 1][j];
            }
            // 대각선 아래 오른쪽
            if (i + 1 <= n && j + 1 <= m && d[i + 1][j + 1] < d[i][j] + a[i + 1][j + 1]) 
            {
                d[i + 1][j + 1] = d[i][j] + a[i + 1][j + 1];
            }
        }
    }
	cout << d[n][m];
	return 0;
}