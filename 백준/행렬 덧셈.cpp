#include<iostream>

using namespace std;

int a[101][101];
int b[101][101];

int main()
{
	int N, M;
	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> b[i][j];
		}
	}

	int answer[101][101];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			answer[i][j] = a[i][j] + b[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << answer[i][j];
			if (j < M - 1)
			{
				cout << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}