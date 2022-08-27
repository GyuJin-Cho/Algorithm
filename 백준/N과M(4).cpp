#include<iostream>

using namespace std;

int n, m;
int arr[9] = { 0, };
void DFS(int num, int Depth)
{
	if (Depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = num; i <= n; i++)
		{
			arr[Depth] = i;
			DFS(i, Depth + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	DFS(1, 0);
	return 0;
}