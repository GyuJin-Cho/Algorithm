#include<iostream>
#include<queue>
using namespace std;

int dx[] = { 1,-1 };
bool visit[100001] = { false, };
void BFS(const int& N, const int& K)
{
	int ans = 0;
	int SearchMax = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));
	int check = 0;
	visit[N] = true;
	int minSec = 0;
	while (!q.empty())
	{
		pair<int, int> n = q.front();
 		q.pop();
		visit[n.first] = true;
		if (n.first == K && check != 0 && minSec == n.second)
			check++;

		if (n.first == K && check==0)
		{
			cout << n.second<<'\n';
			minSec = n.second;
			check++;
		}

		if (2 * n.first < 100001)
		{
			if (!visit[2 * n.first])
			{
				q.push(make_pair(2 * n.first, n.second + 1));
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int nx = n.first + dx[i];
			if (nx >= 0 && nx < 100001)
			{
				if (!visit[nx])
				{
					q.push(make_pair(nx, n.second + 1));
				}
			}
		}

	}
	cout << check;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	BFS(N, K);
	return 0;
}