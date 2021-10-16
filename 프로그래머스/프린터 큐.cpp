#include<iostream>
#include<queue>

using namespace std;

int main()
{
	int Case = 0;
	cin >> Case;
	for (int i = 0; i < Case; i++)
	{
		int N, M;
		cin >> N >> M;

		queue<pair<int, int>>q;
		priority_queue<int> qq;
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;
			q.push({ j,a });
			qq.push(a);
		}

		int count = 0;
		while (!q.empty())
		{
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (qq.top() == value)
			{
				qq.pop();
				++count;
				if (index == M)
				{
					cout << count << endl;
					break;
				}
			}
			else
			{
				q.push({ index,value });
			}
		}

	}

	return 0;
}