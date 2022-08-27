#include<iostream>

using namespace std;

int arr[16] = { 0, };
int n, answer = 0;

bool check(int level)
{
	for (int i = 0; i < level; i++)
	{
		if (arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i)
		{
			return false;
		}
	}
	return true;
}

void NQueen(int x)
{
	if (x == n)
	{
		answer++;
		return;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[x] = i;
			if (check(x))
			{
				NQueen(x + 1);
			}
		}
	}
}

int main()
{
	cin >> n;
	NQueen(0);
	cout << answer;
	return 0;
}