#include<iostream>

using namespace std;

int n, m;
bool visit[9] = { false, };
int arr[9] = { 0, };
void DFS(int depth)
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
			if (!visit[i])
			{
				visit[i] = true;
				arr[depth] = i;
				DFS(depth + 1);
				visit[i] = false;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	DFS(0);
	return 0;
}