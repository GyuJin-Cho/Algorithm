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
int arr[101][101];
int main()
{
	int x1, y1, x2, y2;
	for(int i=0;i<4;i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=y1;j<y2;j++)
		{
			for(int z=x1;z<x2;z++)
			{
				arr[j][z] = 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			if (arr[i][j] == 1)
				ans++;

	cout << ans;
	return 0;
}