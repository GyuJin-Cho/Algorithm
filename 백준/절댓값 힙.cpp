#include<iostream>
#include<queue>
#include<map>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	priority_queue<pair<int, int>> pq;
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << -pq.top().second << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(make_pair(-abs(num),-num));
		}
	}

	return 0;
}