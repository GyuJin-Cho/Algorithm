#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<cstring>

using namespace std;
#define INF 1e9
#define MAX 201
int Graph[MAX][MAX];
int Ans[MAX][MAX];
int main()
{
	int n, m;
	cin >> n >> m;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (i == j)
				Graph[i][j] = 0;
			else
				Graph[i][j] = INF;
		}
	}

	for(int i=0;i<m;i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		Graph[u][v] = c;
		Graph[v][u] = c;
		Ans[u][v] = v;
		Ans[v][u] = u;
	}

	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(Graph[i][j]>Graph[i][k]+Graph[k][j])
				{
					Graph[i][j] = Graph[i][k] + Graph[k][j];
					Ans[i][j] = Ans[i][k];
				}
			}
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if (Ans[i][j] == 0)
				cout << "- ";
			else
				cout << Ans[i][j]<<' ';
		}
		cout << '\n';
	}

	return 0;
}