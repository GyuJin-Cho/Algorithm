#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int answer = 0;
bool visit[100001] = { false, };

int w[3] = { -1,+1, 2 };

void BFS(int N, int K)
{
	queue<pair<int,int>> q;
	q.push(make_pair(N,0));
	
	while (!q.empty())
	{
		int subin = q.front().first;
		answer = q.front().second;
		q.pop();
		visit[subin] = true;

		if (subin == K)
			break;
		int ans = answer + 1;
		for (int i = 0; i < 3; i++)
		{
			if (i == 2)
			{
				if (subin * w[i] > 100000)
				{
					continue;
				}
				if (!visit[subin * w[i]] && subin >= 0 && subin < 100001)
				{
					q.push(make_pair(subin * w[i], ans));
					visit[subin * w[i]] = true;
				}
			}
			else if (!visit[subin + w[i]] && subin >= 0 &&  subin < 100001)
			{
				q.push(make_pair(subin + w[i], ans));
				visit[subin + w[i]] = true;
			}
		}

	}
}

int main()
{
	int N, K;
	cin >> N >> K;

	BFS(N, K);
	cout << answer;


	return 0;
}