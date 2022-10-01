#include<iostream>
#include<queue>
#include<string>
#pragma warning(disable:4996)
using namespace std;

int answer = 0;
bool visit[10001];
struct node
{
	int Position;
	string ans;
};

char Order[] = { 'D','S','L','R' };

void InitVisit()
{
	for (int i = 0; i < 10001; i++)
	{
		visit[i] = false;
	}
}

string BFS(const int& start, const int& goal)
{
	queue<node> q;
	q.push({ start,"" });
	visit[start] = true;

	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		if (n.Position == goal)
		{
			return n.ans;
		}
		for (int i = 0; i < 4; i++)
		{
			switch (Order[i])
			{
				case 'D':
				{
					int d = (n.Position * 2) % 10000;
					if (!visit[d])
					{
						visit[d] = true;
						q.push({ d,n.ans + "D" });
					} 
					break;
				}
				case 'S':
				{
					
					if (n.Position == 0)
					{
						if (!visit[9999])
						{
							visit[9999] = true;
							q.push({ 9999,n.ans + "S" });
						}
					}
					else
					{
						int d = n.Position - 1;
						if (!visit[d])
						{
							visit[d] = true;
							q.push({ d,n.ans + "S" });
						}
					}
					break;
				}
				case 'L':
				{
					int np = (n.Position % 1000) * 10 + (n.Position / 1000);
					if (!visit[np])
					{
						visit[np] = true;
						q.push({ np,n.ans + "L" });
					}
					break;
				}
				case 'R':
				{
					
					int np = (n.Position % 10) * 1000 + (n.Position / 10);
					if (!visit[np])
					{
						visit[np] = true;
						q.push({ np,n.ans + "R" });
					}
					break;
				}
			}
		}
	}
}

int main()
{

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int start;
		int goal;
		scanf("%d%d", &start, &goal);
		InitVisit();
		cout << BFS(start, goal);
		if (i<n-1)
		{
			cout << "\n";
		}
	}

	return 0;
}