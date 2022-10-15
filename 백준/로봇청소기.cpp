#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

int map[51][51];
int r, c;
tuple<int, int, int> Robot;
bool CleanUp[51][51];
int answer = 0;

bool BackClean = true;
bool DirectionCheck = false;
vector<bool> v;
bool endGame = true;
void CleanMap()
{
	for (int i = 0; i < 51; i++)
	{
		for (int j = 0; j < 51; j++)
		{
			if (CleanUp[i][j]&&map[i][j]!=1)
				answer++;
		}
	}
}
void FirstCheck()
{
	CleanUp[get<0>(Robot)][get<1>(Robot)] = true;
}
void ThirdCheck()
{
	int y = get<0>(Robot);
	int x = get<1>(Robot);
	int Direction = get<2>(Robot);

	if (Direction == 0)
	{
		if (y + 1 < r)
		{
			if (map[y+1][x] != 1)
			{
				Robot = make_tuple(y+1, x, 0);
				
				return;
			}
		}
	}
	else if (Direction == 1)
	{
		if (x - 1 >= 0)
		{
			if (map[y][x-1] != 1)
			{
				Robot = make_tuple(y, x-1, 1);

				return;
			}
		}
	}
	else if (Direction == 2)
	{
		if (y - 1 >= 0)
		{
			if (map[y-1][x] != 1)
			{
				Robot = make_tuple(y-1, x, 2);

				return;
			}
		}
	}
	else if (Direction == 3)
	{
		if (x + 1 < c)
		{
			if (map[y][x+1] != 1)
			{
				Robot = make_tuple(y, x+1, 3);

				return;
			}
		}
	}
	BackClean = false;
}
void SecondCheck()
{
	int y = get<0>(Robot);
	int x = get<1>(Robot);
	int Direction = get<2>(Robot);
	if (Direction == 0)
	{
		if (x - 1 >= 0)
		{
			if (!CleanUp[y][x - 1]&&map[y][x-1]!=1)
			{
				Robot = make_tuple(y, x - 1, 3);
				
				FirstCheck();
				return;
			}
		}
	}
	else if (Direction == 1)
	{
		if (y - 1 >= 0)
		{
			if (!CleanUp[y-1][x] && map[y-1][x] != 1)
			{
				Robot = make_tuple(y-1, x, 0);
				FirstCheck();
				
				return;
			}
		}
	}
	else if (Direction == 2)
	{
		if (x + 1 < c)
		{
			if (!CleanUp[y][x+1] && map[y][x + 1] != 1)
			{
				Robot = make_tuple(y, x+1, 1);
				
				FirstCheck();
				return;
			}
		}
	}
	else if (Direction == 3)
	{
		if (y + 1 < r)
		{
			if (!CleanUp[y + 1][x] && map[y+1][x] != 1)
			{
				Robot = make_tuple(y + 1, x, 2);
				
				FirstCheck();
				return;
			}
		}
	}
	if (v.size() == 4)
	{
		if (BackClean)
		{
			v.clear();
			ThirdCheck();
			if (!BackClean)
			{
				endGame = false;
				CleanMap();
			}
			return;
		}
	}

	if (Direction == 0)
	{
		Robot = make_tuple(y, x, 3);
	}
	else
	{
		Robot = make_tuple(y, x, Direction - 1);
	}
	v.push_back(true);
	
	SecondCheck();	
}

void Search()
{
	FirstCheck();
	while (endGame)
	{
		v.clear();
		SecondCheck();
	}
		
	
}

int main()
{

	cin >> r >> c;
	int y, x, direction;
	
	cin >> y >> x >> direction;
	Robot = make_tuple(y, x, direction);

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	Search();

	cout << answer;

	return 0;
}