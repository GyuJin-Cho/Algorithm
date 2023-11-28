#include<iostream>
#include<algorithm>
#include<vector>

#include<set>
using namespace std;

int n, m;
int arr[9] = { 0, };
int N[9] = { 0 , };
bool visit[9] = { false, };
set<vector<int>> s;
void DFS(int Depth, int num)
{
	if (m == Depth)
	{
		vector<int> v;
		for (int i = 0; i < m; i++)
		{
			v.push_back(arr[i]);
		}
		s.insert(v);
		v.clear();
	}
	else
	{
		for (int i = num; i < n; i++)
		{
			arr[Depth] = N[i];
			num = i;
			DFS(Depth + 1, num);
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
	DFS(0, 0);

	for (auto vector : s)
	{
		for (auto set : vector)
		{
			cout << set << " ";
		}
		cout << "\n";
	}

	return 0;
}