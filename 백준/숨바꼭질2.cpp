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
constexpr int MAX = 100001;
int dx[] = { 1,-1 };
bool visit[MAX] = { false, };
void BFS(const int& N, const int& K)
{

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

		if (n.first == K && check == 0)
		{
			cout << n.second << '\n';
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, K;
	cin >> N >> K;
	BFS(N, K);
	return 0;
}