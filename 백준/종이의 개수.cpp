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
#include<cstring>

using namespace std;
int ans[3];
int arr[2200][2200];

bool ch(int num ,int y, int x )
{
	int s = arr[y][x];
	for(int i=y;i<y+num;i++)
	{
		for(int j=x;j<x+num;j++)
		{
			if (s != arr[i][j])
				return false;
		}
	}
	return true;
}

void Divide(int size, int y, int x)
{
	if(ch(size,y,x))
	{
		ans[arr[y][x]]++;
	}
	else
	{
		int DivideSize = size / 3;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				Divide(DivideSize, y + DivideSize * i, x + DivideSize * j);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,num;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin >> num;
			num++;
			arr[i][j] = num;
		}
	}
	Divide(n, 0, 0);
	cout << ans[0] << '\n';
	cout << ans[1] << '\n';
	cout << ans[2];

	return 0;
}