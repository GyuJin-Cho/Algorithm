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
const int MAX = 500000;
int n, k;
int visit[MAX+1][2];

int GetSum(int n)
{
	return n * (n + 1) / 2;
}

void MoveOfSubin()
{
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ n,0 });

	while(!q.empty())
	{
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		if(now<0||now>MAX)
			continue;
		if(visit[now][time%2]!=-1)
			continue;
		visit[now][time % 2] = time;
		q.push({ now * 2,time + 1 });
		q.push({ now - 1,time + 1 });
		q.push({ now + 1,time + 1 });

	}
}

void MoveOfSister()
{
	for(int t=0;t<MAX;t++)
	{
		int sister = k + GetSum(t);
		if (sister > MAX)
			break;
		if(visit[sister][t%2]!=-1&&visit[sister][t%2]<=t)
		{
			cout << t;
			return;
		}
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	MoveOfSubin();
	MoveOfSister();

	return 0;
}