#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
bool visit[9] = { false, };
int arr[9] = { 0, };
int N[9] = { 0, };

void DFS(int Depth)
{
	if (Depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i]<<" ";
		}
		cout << "\n";
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!visit[i])
			{
				visit[i] = true;
				arr[Depth] = N[i - 1];
				DFS(Depth + 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> N[i];
	sort(N, N + n);
	DFS(0);
	return 0;
}