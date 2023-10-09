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
int board[101][101];
int s[101][101];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int x, y;
		cin >> x >> y;
		for (int i = y; i < y + 10; i++)
		{
			for (int j = x; j < x + 10; j++)
			{
				board[i][j] = 1;
			}
		}
	}

	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			if (board[i][j] == 1)
				s[i][j] = s[i][j - 1] + board[i][j];
		}
	}

	int answer = 0;

	for (int i = 1; i < 100; i++)
	{
		for (int j = 1; j < 100; j++)
		{
			if (board[i][j] == 0)
				continue;
			int height = 0;
			int width = s[i][j];
			for (int k = i; k >= 1; k--)
			{
				if (s[k][j] == 0)
					break;
				height++;
				width = min(width, s[k][j]);
				if (answer < width * height)
					answer = width * height;
			}
		}
	}
	cout << answer;
	return 0;
}