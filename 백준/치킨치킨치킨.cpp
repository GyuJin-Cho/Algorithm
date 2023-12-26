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
int arr[31][31];
int pick[3];
int res;

void comb(int idx, int cnt)
{
	if (cnt != -1)
		pick[cnt] = idx;

	if(cnt==2)
	{
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			int score = 0;
			for(int j=0;j<3;j++)
			{
				score = max(arr[i][pick[j]], score);
			}
			sum += score;
		}
		res = max(sum, res);
		return;
	}
	for (int i = idx; i < m; i++)
		comb(i + 1, cnt + 1);
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	comb(-1, - 1);
	cout << res;
	return 0;
}