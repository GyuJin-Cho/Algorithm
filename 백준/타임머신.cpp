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

const int MAXN = 510;
const int INF = 1<<30;

vector<pair<int, int>> arr[MAXN];
long long d[MAXN];
bool inq[MAXN];
int cnt[MAXN];
int N, M;
int cycle[MAXN];
void SPFA()
{
	queue<int> q;
	q.push(1);
	inq[1] = true;
	cycle[1]++;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();

		inq[now] = false;
		for(int i=0;i<arr[now].size();i++)
		{
			int next = arr[now][i].first;
			int cost = arr[now][i].second;

			if(d[next]>d[now]+cost)
			{
				d[next] = d[now] + cost;

				if(!inq[next])
				{
					cycle[next]++;
					if(cycle[next]>=N)
					{
						cout << -1;
						return;
					}
					q.push(next);
					inq[next] = true;
				}
			}
		}
	}
	for(int i=2;i<=N;i++)
	{
		cout << (d[i] == INF ? -1 : d[i]) << '\n';
	}
}

int main()
{
	cin >> N >> M;

	for(int i=0;i<M;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
	}
	for (int i = 2; i <= N; i++)
		d[i] = INF;
	SPFA();
	return 0;
}