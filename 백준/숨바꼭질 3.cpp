#include<iostream>
#include<queue>

using namespace std;

bool visit[200000] = { false, };
int go[] = { 1,-1 };


int BFS(const int& N, const int& K)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0,N));
	visit[N] = true;
	while (!q.empty())
	{
		pair<int,int> n = q.top();
		q.pop();
		if (n.second == K)
		{
			return n.first;
		}
		
		if (2 * n.second < 200000)
		{
			if (!visit[2 * n.second])
			{
				q.push({ n.first,2*n.second});
				visit[2 * n.second] = true;
			}
		}
		for (int i = 0; i < 2; i++)
		{
			int nMove = go[i] + n.second;
			if (nMove >= 0 && nMove < 200000)
			{
				if (!visit[nMove])
				{
					q.push({ n.first + 1, nMove });
					visit[nMove] = true;
				}
			}
		}
		
		
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	cout<<BFS(N, K);
	return 0;
}