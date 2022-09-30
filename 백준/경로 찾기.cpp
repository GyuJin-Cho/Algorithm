#include<iostream>

using namespace std;

int answer[101][101] = { 0, };

int main()
{
	int N = 0;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> answer[i][j];
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (answer[i][k] && answer[k][j])
					answer[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout<< answer[i][j]<<" ";
		}
		cout << endl;
	}

	return 0;
}