#include<iostream>
#include<string>

using namespace std;
int map[501][501];
int main()
{
	int N, M, B;
	int mintime = 1234567890;
	int maxheight = -1;
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int height = 0; height <= 256; height++) 
	{
		int inven = 0;
		int remove = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++) 
			{
				int curheight = map[i][j] - height;
				if (curheight < 0) inven -= curheight;
				else remove += curheight;
			}
		}
		if (remove + B >= inven) 
		{
			int ttime = 2 * remove + inven;
			if (mintime >= ttime) 
			{
				mintime = ttime;
				maxheight = height;
			}
		}
	}
	cout << mintime << " " << maxheight;
	return 0;
}