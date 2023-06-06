#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class DDackChi
{
public:
	int star;
	int circle;
	int	square;
	int triangle;

public:
	DDackChi(int star = 0, int circle = 0, int square = 0, int triangle = 0) : star(star), circle(circle), square(square), triangle(triangle){}
};

int main()
{
	int N;
	cin >> N;

	while(N--)
	{
		int a;
		cin >> a;
		int aNum;
		DDackChi A;
		DDackChi B;
		while(a--)
		{
			cin >> aNum;
			switch (aNum)
			{
				case 4:
					{
						A.star++;
						break;
					}
				case 3:
					{
						A.circle++;
						break;
					}
				case 2:
					{
						A.square++;
						break;
					}
				case 1:
					{
						A.triangle++;
						break;
					}
			}
		}
		int b;
		cin >> b;
		int bNum;
		while(b--)
		{
			cin >> bNum;
			switch (bNum)
			{
				case 4:
					{
						B.star++;
						break;
					}
				case 3:
					{
						B.circle++;
						break;
					}
				case 2:
					{
						B.square++;
						break;
					}
				case 1:
					{
						B.triangle++;
						break;
					}
			}
		}

		if (A.star > B.star)
			cout << "A" << '\n';
		else if(A.star<B.star)
			cout << "B" << '\n';
		else if (A.star == B.star)
		{
			if (A.circle > B.circle)
				cout << "A" << '\n';
			else if (A.circle < B.circle)
				cout << "B" << '\n';
			else if(A.circle==B.circle)
			{
				if (A.square > B.square)
					cout << "A" << '\n';
				else if (A.square < B.square)
					cout << "B" << '\n';
				else if(A.square==B.square)
				{
					if (A.triangle > B.triangle)
						cout << "A" << '\n';
					else if (A.triangle < B.triangle)
						cout << "B" << '\n';
					else
					{
						cout << "D" << '\n';
					}
				}
			}
		}
	}

	return 0;
}