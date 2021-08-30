#include<iostream>
#include<string>

using namespace std;
int map[500][500];
int main()
{
	int N;
	int M;
	int B;
	cin >> N>> M>> B;
	int min=INT_MAX;
	int max=-1;
	int countMin = 0;
	int countMax = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (min > map[i][j])
			{
				min = map[i][j];
			}
			if (max < map[i][j])
			{
				max = map[i][j];
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (min != map[i][j])
			{
				countMin += 2;
				B++;
				map[i][j]--;
			}
			if(max!=map[i][j]&&B>=1)
			{
				countMax++;
				B--;
				map[i][j]++;
			}
		}
	}
	if (countMax > countMin)
		cout << countMin << " " << map[0][0];
	else if (countMax < countMin)
		cout << countMax << " " << map[0][0];
	return 0;
}