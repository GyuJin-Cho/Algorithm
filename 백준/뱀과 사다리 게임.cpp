#include<iostream>
#include<queue>
#include<map>
using namespace std;
map<int, int> Telport;
int answer = 999999;
bool visit[101] = { false, };
struct node
{
	int Position = 0;
	int Couont = 0;
};
void BFS()
{
	queue<node> q;
	q.push({ 1,0 });

	visit[1] = true;

	while (!q.empty())
	{
		int position = q.front().Position;
		int count = q.front().Couont;
		if (position == 100)
		{
			answer = min(answer, count);
			break;
		}
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			int np = position + i;
			if (np > 100 || visit[np])
				continue;
			visit[np] = true;
			if (Telport[np] == 0)
			{
				q.push({ np,count + 1 });
			}
			else if (Telport[np] != 0)
			{
				q.push({ Telport[np],count + 1 });
				visit[Telport[np]] = true;
			}
		}
	}
}

int main()
{
	int L, S;
	cin >> L >> S;
	for (int i = 0; i < L; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		Telport.insert({ x,y });
	}
	for (int i = 0; i < S; i++)
	{
		int x;
		int y;
		cin >> x >> y;
		Telport.insert({ x,y });
	}

	BFS();
	cout << answer;

	return 0;
}