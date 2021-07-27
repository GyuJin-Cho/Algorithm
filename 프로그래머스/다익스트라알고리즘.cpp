#include<iostream>
#include<queue>
#include<string>
#include<vector>

using namespace std;

#define INF 100000
int     number = 6;

vector<pair<int, int>> a[7];
int d[7];

void diijkstra(int start)
{
	d[start] = 0;

	priority_queue<pair<int, int>> q;
	q.push(make_pair(start, 0));


	while (!q.empty())
	{
		int current = q.top().first;
		int distance = -q.top().second;
		q.pop();
		for (int i = 0; i < a[current].size(); i++)
		{
			int Next = a[current][i].first;
			int NextDistance = distance + (a[current][i].second);
			if (NextDistance < d[Next])
			{
				d[Next] = NextDistance;
				q.push(make_pair(Next, -NextDistance));
			}
			
		}
	}
}

int main()
{
	for (int i = 0; i < number; i++)
	{
		d[i] = INF;
	}
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(3, 5));
	a[1].push_back(make_pair(4, 1));

	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[2].push_back(make_pair(4, 2));

	a[3].push_back(make_pair(1, 5));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 3));
	a[3].push_back(make_pair(5, 1));
	a[3].push_back(make_pair(6, 5));

	a[4].push_back(make_pair(1, 1));
	a[4].push_back(make_pair(2, 2));
	a[4].push_back(make_pair(3, 3));
	a[4].push_back(make_pair(5, 1));

	a[5].push_back(make_pair(3, 1));
	a[5].push_back(make_pair(4, 1));
	a[5].push_back(make_pair(6, 2));

	a[6].push_back(make_pair(3, 5));
	a[6].push_back(make_pair(5, 2));
	diijkstra(1);

	for (int i = 0; i < number; i++)
	{
		printf("%d\n", d[i]);
	}
	return 0;
}