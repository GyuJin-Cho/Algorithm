#include<iostream>

using namespace std;

int dist[100001];
int cost[100001];

int main()
{
	int n;
	long long total = 0;
	long long now;
	cin >> n;
	for(int i=1;i<n;i++)
	{
		cin >> dist[i];
	}
	for(int i=0;i<n;i++)
	{
		cin >> cost[i];
	}

	now = cost[0];
	total = now * dist[1];

	for(int i=1;i<n;i++)
	{
		if(now<cost[i])
		{
			total += now * dist[i + 1];
		}
		else
		{
			now = cost[i];
			total += now * dist[i + 1];
		}
	}
	cout << total;
}