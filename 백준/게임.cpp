#include<iostream>
#define MAX 1000000000
using namespace std;
long long x, y, Z;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> x >> y;

	Z = y*100 /x;

	int start = 0;
	int end = MAX;

	if(Z >= 99)
	{
		cout << -1;
		return 0;
	}
	while (start <= end)
	{
		int mid = (start + end) / 2;
		int Div = (y+mid)*100 / (x+mid);
		if (Div > Z)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}

	}
	cout << start;
	return 0;
}