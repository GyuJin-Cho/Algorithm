#include<iostream>
#include<queue>
#pragma warning(disable:4996)
using namespace std;

int main()
{
	priority_queue<int> pq;
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int x = 0;
		scanf("%d", &x);
		if (x == 0)
		{
			if (pq.empty())
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}