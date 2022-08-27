#include<iostream>
#include<algorithm>

using namespace std;
int n, m;
int arr[9] = { 0, };
int N[9] = { 0, };

void DFS(int Depth)
{
	if (m == Depth)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[Depth] = N[i - 1];
			DFS(Depth + 1);
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
	DFS(0);

	return 0;
}