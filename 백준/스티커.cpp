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

int arr[2][100001];
unsigned long long d[2][100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,N;
	cin >> T;

	while(T--)
	{
		cin >> N;
		for(int i=0;i<2;i++)
		{
			for(int j=1;j<=N;j++)
			{
				cin >> arr[i][j];
			}
		}

		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = arr[0][1];
		d[1][1] = arr[1][1];
		for (int j = 2; j <= N; j++)
		{
			d[0][j] = max(d[1][j - 2], d[1][j - 1]) + arr[0][j];
			d[1][j] = max(d[0][j - 2], d[0][j - 1]) + arr[1][j];
		}
		cout << max(d[0][N], d[1][N])<<'\n';
	}
	return 0;
}