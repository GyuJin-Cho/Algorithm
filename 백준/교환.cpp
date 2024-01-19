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

string BFS(string start, int count)
{
	int length = start.size();
	queue<string> q;
	q.push(start);

	for (int i = 0; i < count; i++)
	{
		set<string> visit;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			string start = q.front();
			q.pop();
			if (visit.count(start))
				continue;
			visit.insert(start);

			for (int a = 0; a < length - 1; a++)
			{
				for (int b = a + 1; b < length; b++)
				{
					if (a == 0 && start[b] == '0')
						continue;
					swap(start[a], start[b]);
					q.push(start);
					swap(start[a], start[b]);
				}
			}
		}
	}
	string answer = "0";
	while (!q.empty())
	{
		answer = max(answer, q.front());
		q.pop();
	}
	if (answer[0] == '0')
		return "-1";
	else
		return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string n;
	int K;
	cin >> n >> K;
	
	cout << BFS(n,K);
	return 0;
}