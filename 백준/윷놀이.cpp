#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int cnt;
	int a;
	for(int i=0;i<3;i++)
	{
		cnt = 0;
		for(int j=0;j<4;j++)
		{
			cin >> a;
			if (a == 1)
				cnt++;
		}
		switch (cnt)
		{
			case 1:
			{
				cout << 'C' << '\n';
				break;
			}
			case 2:
			{
				cout << 'B' << '\n';
				break;
			}
			case 3:
			{
				cout << 'A' << '\n';
				break;
			}
			case 4:
			{
				cout << 'E' <<'\n';
				break;
			}
			case 0:
			{
				cout<< 'D' << '\n';
				break;
			}
		}
	}
	return 0;
}