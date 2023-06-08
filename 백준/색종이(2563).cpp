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

int arr[101][101];

int main()
{
	int n;
	cin >> n;
	int x, y;
	while(n--)
	{
		cin >> x >> y;
		for (int i = y; i < y + 10; i++)
			for (int j = x; j < x + 10; j++)
				arr[i][j] = 1;
	}
	int ans = 0;
	for (int i = 0; i <=100; i++)
		for (int j = 0; j <=100; j++)
		{
			if (arr[i][j] == 1)
				ans++;
		}
	cout << ans;
	return 0;
}