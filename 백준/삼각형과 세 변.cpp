#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>

using namespace std;

int main()
{
	int X, Y, Z;
	while (1)
	{
		cin >> X >> Y >> Z;
		int x=0, y=0, z=0;
		if (X == 0 && Y == 0 && Z == 0)
		{
			break;
		}
		if (X > Y && X > Z)
		{
			x = X;
		}
		else if (Y > X && Y > Z)
		{
			y = Y;
		}
		else if (Z > X && Z > Y)
		{
			z = Z;
		}

		if (x != 0)
		{
			if (x >= Y + Z)
			{
				cout << "Invalid" << '\n';
				continue;
			}
		}
		else if (y != 0)
		{
			if (y >= X + Z)
			{
				cout << "Invalid" << '\n';
				continue;
			}
		}
		else
		{
			if (z >= X + Y)
			{
				cout << "Invalid" << '\n';
				continue;
			}
		}
		
		if (X == Y && X == Z && Y == Z)
		{
			cout << "Equilateral"<<'\n';
		}
		else if (X != Y && X != Z && Y != Z)
		{
			cout << "Scalene" << '\n';
		}
		else
		{
			cout << "Isosceles" << '\n';
		}

	}

	return 0;
}