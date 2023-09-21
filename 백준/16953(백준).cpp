#include<iostream>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

void BFS(int n, int t)
{
	queue<pair<long long, int>> q;
	q.push(make_pair(n, 1));
	int answer = 0;
	while (!q.empty())
	{
		long long d = q.front().first;
		int cur = q.front().second;
		if (d == t)
		{
			answer = cur;
			break;
		}
		q.pop();

		if (d > t)
			continue;
		q.push(make_pair(d * 2, cur + 1));
		string a = to_string(d);
		a += "1";
		q.push(make_pair(stoll(a), cur + 1));
	}
	if (q.empty())
	{
		cout << -1 << endl;
	}
	else
	{
		cout << answer;
	}
}

int main()
{
	int n, t;
	cin >> n >> t;
	BFS(n, t);

	return 0;
}