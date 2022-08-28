#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
int arr[9] = { 0, };
int N[9] = { 0, };
vector<int> v;
set<vector<int>> s;

void DFS(int Num, int Depth)
{
	if (Depth == m)
	{
		for (int i = 0; i < m; i++)
		{
			v.push_back(arr[i]);
		}
		s.insert(v);
		v.clear();
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			arr[Depth] = N[i];
			DFS(i, Depth + 1);
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> N[i];
	sort(N, N + n);
	DFS(0, 0);
	for (auto vector : s)
	{
		for (auto set : vector)
		{
			cout << set<<" ";
		}
		cout << "\n";
	}

	return 0;
}