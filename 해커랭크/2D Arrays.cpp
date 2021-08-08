#include<iostream>

using namespace std;
int board[50][50];
int main()
{
	
	int a;
	int Max = -100;
	int sum = 0;
	int X = 1;
	int Y = 1;
	for(int i=0;i<6;i++)
		for (int j = 0; j < 6; j++)
		{
			cin >> a;
			board[i][j] = a;
		}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum=board[i][j] + board[i][j + 1] + board[i][j + 2]+board[X][Y]+board[i+2][j]+board[i+2][j+1]+board[i+2][j+2];
			if (Max < sum)
				Max = sum;
			Y++;
		}
		sum = 0;
		X++;
		Y = 1;
	}
	cout << Max;
	return 0;
}