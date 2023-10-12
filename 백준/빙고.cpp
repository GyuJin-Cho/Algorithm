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
int arr[5][5];
pair<int, int> num[26];

bool check()
{
	int bingo = 0;
	int crossR = 0;
	int crossL = 0;
	for (int i = 0; i < 5; i++) 
	{
		int col = 0;
		int row = 0;
		for (int j = 0; j < 5; j++) 
		{
			if (arr[i][j] == 0) 
			{
				row++;
			}
			if (arr[j][i] == 0) 
			{
				col++;
			}
		}
		if (col == 5) 
		{
			bingo++;
		}
		if (row == 5) 
		{
			bingo++;
		}
		if (arr[i][i] == 0) 
		{
			crossR++;
		}
		if (arr[i][4 - i] == 0) 
		{
			crossL++;
		}
	}
	if (crossR == 5) 
	{
		bingo++;
	}
	if (crossL == 5) 
	{
		bingo++;
	}
	if (bingo >= 3)
	{
		return true;
	}
	return false;
}

int main()
{
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			cin >> arr[i][j];
			num[arr[i][j]] = { i,j };
		}
	}
	int ans = 0;
	for (int i = 0; i < 5; i++) 
	{
		for (int j = 0; j < 5; j++) 
		{
			ans++;
			int number;
			cin >> number;
			arr[num[number].first][num[number].second] = 0;
			if (i > 1) 
			{
				if (check()) 
				{
					cout << ans;
					return 0;
				}
			}
		}
	}

	return 0;
}