#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int H, W, N;
	
	int count = 0;
	int HO = 0;
	int Num = 0;
	int n;
	cin >> n;
	bool check = false;
	for (int z = 0; z < n; z++)
	{
		check = false;
		HO = 0;
		Num = 0;
		count = 0;
		cin >> H >> W >> N;
		for (int i = 0; i < W; i++)
		{
			Num++;
			for (int j = 0; j < H; j++)
			{
				count++;
				HO++;
				if (count == N)
				{
					cout << HO * 100 + Num<<endl;
					check = true;
					break;
				}
			}
			HO = 0;
			if (check)
				break;
		}
	}
	
	return 0;
}