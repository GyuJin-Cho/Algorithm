#include<iostream>
#include<vector>

using namespace std;

int solution(vector<vector<int>> land)
{
	int sum = 0;

	int size = land[0].size();
	
	int col = land.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int z = 0; z < size; z++)
			{
				if (i == j || j == z)
					continue;

				int sum1=0;
				for (int k = 0; k < col; k++)
				{
					sum1
				}
			}
		}
	}
}

int main()
{
	vector<vector<int>> v = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };

	cout << solution(v);

	return 0;
}