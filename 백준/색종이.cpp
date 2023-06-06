#include<iostream>

using namespace std;
int map[1002][1002];
int main()
{
	
	int n;
	cin >> n;
	int x, y, w, h;
	for(int i=1;i<=n;i++)
	{
		cin >> x >> y >> w >> h;
		for(int dx = x;dx<x+w;dx++)
		{
			for(int dy = y;dy<y+h;dy++)
			{
				map[dx][dy] = i;
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		int sum = 0;
		for(int dx = 0;dx< 1002;dx++)
		{
			for(int dy = 0;dy< 1002;dy++)
			{
				if(map[dx][dy]==i)
				{
					sum++;
				}
			}
		}
		cout << sum << '\n';
	}

	return 0;
}