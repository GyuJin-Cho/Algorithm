#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> studentview(N,vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &studentview[i][j]);
	vector<vector<bool>> check(N, vector<bool>(N));

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<N-1;j++)
		{
			for(int z=j+1;z<N;z++)
			{
				if(studentview[j][i]==studentview[z][i])
				{
					check[j][z] = true;
					check[z][j] = true;
				}
			}
		}
	}
	int answer = -1;
	int prevCount = -1;
	for(int i=0;i<N;i++)
	{
		int count = 0;
		for(int j=0;j<N;j++)
		{
			if (check[i][j])
				count++;
		}
		if(count>prevCount)
		{
			answer = i + 1;
			prevCount = count;
		}
	}
	printf("%d", answer);
	return 0;
}