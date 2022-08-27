#include<iostream>

using namespace std;

int n, m;
int arr[9] = { 0, };
void DFS(int num, int depth)
{
	if (m == depth)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[depth] = i;
			DFS(i, depth + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	DFS(1, 0);
	return 0;
}