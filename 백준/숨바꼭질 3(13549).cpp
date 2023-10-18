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
constexpr int MAX = 200000;
int N, K;
bool visit[MAX];
void BFS()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0,N));
	visit[N] = true;
	while(!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		if(p.second==K)
		{
			cout << p.first;
			return;
		}

		for(int i=0;i<3;i++)
		{
			int nx;
			bool mulch = false;
			if(i==0)
			{
				nx = p.second * 2;
				mulch = true;
			}
			else if(i==1)
			{
				nx = p.second - 1;
			}
			else
			{
				nx = p.second + 1;
			}
			if ( nx < MAX && !visit[nx] && nx > -1 )
			{
				if(mulch)
				{
					pq.push(make_pair(p.first, nx));
					visit[nx] = true;
				}
				else
				{
					pq.push(make_pair(p.first + 1, nx));
					visit[nx] = true;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	BFS();
	return 0;
}