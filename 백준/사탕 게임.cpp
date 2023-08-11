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

int MaxCount;
void ColumnCandy(char Map[51][51], int size)
{
	for (int i = 0; i < size; i++)
	{
		int count = 1;
		for (int j = 0; j < size; j++)
		{
			if (Map[i][j] == Map[i][j + 1])
			{
				count++;
			}
			else
			{
				if (count > MaxCount)
				{
					MaxCount = count;
				}
				count = 1;
			}
		}
	}
}

void RowCandy(char Map[51][51],int size)
{
	for (int i = 0; i < size; i++)
	{
		int count = 1;
		for (int j = 0; j < size; j++) 
		{
			if (Map[j][i] == Map[j + 1][i])
				count++;
			else {
				if (count > MaxCount)
					MaxCount = count;
				count = 1;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	char Map[51][51];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> Map[i][j];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n-1; j++)
		{
			swap(Map[i][j], Map[i][j + 1]);

			RowCandy(Map, n);
			ColumnCandy(Map, n);

			swap(Map[i][j + 1], Map[i][j]);

			swap(Map[j][i], Map[j + 1][i]);

			RowCandy(Map, n);
			ColumnCandy(Map, n);

			swap(Map[j][i], Map[j + 1][i]);
		}
	}
	cout << MaxCount;
	return 0;
}