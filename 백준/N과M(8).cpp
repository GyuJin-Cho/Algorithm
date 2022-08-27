#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int arr[9] = { 0, };
int N[9] = { 0, };

void DFS(int num, int Depth)
{
	if (m == Depth)
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
			arr[Depth] = N[i - 1];
			DFS(i, Depth + 1);
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> N[i];
	}
	sort(N, N + n);
	DFS(1, 0);
	return 0;
}