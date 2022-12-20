#include<iostream>

using namespace std;

int arr[10][10];
int MAX = -1;
int main()
{
	int inp;
	int col, row;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++)
		{
			cin >> inp;
			arr[i][j] = inp;
			if(MAX<inp)
			{
				col = i;
				row = j;
				MAX = inp;
			}
		}
	}

	cout << MAX << endl << col << " " << row;

}