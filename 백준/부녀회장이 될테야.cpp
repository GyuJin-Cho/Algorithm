#include<iostream>

using namespace std;

int apart[15][15];
void Init()
{
	for (int i = 0; i < 15; i++)
	{
		apart[0][i] = i + 1;
		apart[i][0] = 1;
	}
	int count = 0;
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			for (int z = 0; z <= j; z++)
			{
				apart[i][j] += apart[i - 1][z];
			}
		}
	}
}
int main()
{
	int T;
	cin >> T;
	int K, N;
	Init();
	for (int i = 0; i < T; i++)
	{
		cin >> K >> N;
		cout << apart[K][N-1] << endl;
	}
	return 0;
}