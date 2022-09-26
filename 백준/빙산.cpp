#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;
int arr[301][301] = { 0, };

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[301][301] = { false, };

void InitVist()
{
	for (int i = 0; i < 301; i++)
	{
		for (int j = 0; j < 301; j++)
		{
			visit[i][j] = false;
		}
	}
}

int Search(const int& Y, const int& X)
{
	
	int answer = 0;
	while (true)
	{
		bool check = false;
		int count = 0;
		InitVist();
		answer++;
		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (arr[i][j] > 0 &&!visit[i][j])
				{
					check = true;
					count++;
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					while (!q.empty())
					{
						pair<int, int> n = q.front();
						q.pop();

						for (int z = 0; z < 4; z++)
						{
							int ny = n.first + dy[z];
							int nx = n.second + dx[z];
							if (ny >= 0 && nx >= 0 && nx < X && ny < Y)
							{
								if (arr[ny][nx] > 0)
								{
									if (!visit[ny][nx])
									{
										q.push(make_pair(ny, nx));
										visit[ny][nx] = true;
									}
								}
								
							}
						}
					}
				}
			}
		}
		vector<pair<int, int>>v;
		for (int i = 0; i < Y; i++)
		{
			for (int j = 0; j < X; j++)
			{
				if (arr[i][j] > 0)
				{
					v.push_back(make_pair(i, j));
				}
			}
		}
		vector<tuple<int, int, int>> map;
		for (auto i : v)
		{
			int zeroCount = 0;
			for (int j = 0; j < 4; j++)
			{
				int ny = i.first + dy[j];
				int nx = i.second + dx[j];
				if (ny >= 0 && nx >= 0 && ny < Y && nx < X)
				{
					if (arr[ny][nx] == 0)
					{
						zeroCount++;
					}
				}
			}
			if (arr[i.first][i.second] - zeroCount < 0)
			{
				map.push_back(make_tuple(i.first, i.second, 0));
			}
			else
			{
				int div = arr[i.first][i.second] - zeroCount;
				map.push_back(make_tuple(i.first, i.second, div));
			}
		}

		for (auto i : map)
		{
			arr[get<0>(i)][get<1>(i)] = get<2>(i);
		}

		if (!check)
			return 0;

		if (count >= 2)
			return answer-1;
	}


}

int main()
{
	int Y, X;
	cin >> Y >> X;

	for (int i = 0; i < Y; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> arr[i][j];
		}
	}

	cout << Search(Y, X);

	return 0;
}