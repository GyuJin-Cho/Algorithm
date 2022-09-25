#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct node
{
	int postion = 0;
	int ans = 0;
};
int answer = 0;
bool visit[1000001] = { false, };
bool BFS(const int& F, const int& S, const int& G, const int& U, const int& D)
{
	queue<node> q;
	q.push({ S,0 });
	vector<int> UD(2);
	visit[S] = true;
	UD[0] = U;
	UD[1] = -D;
	
	while (!q.empty())
	{
		node n = q.front();
		q.pop();
		answer = ++n.ans;
		if (n.postion == G)
		{
			return true;
		}
		
		for (int i = 0; i < UD.size(); i++)
		{
			int Pos = UD[i] + n.postion;
			if (Pos > 0 && Pos <= F)
			{
				if (!visit[Pos])
				{
					q.push({ Pos,answer });
					visit[Pos] = true;
				}
			}
		}
	}
	return false;
}

int main()
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	if (BFS(F, S, G, U, D))
	{
		cout << answer-1;
	}
	else
	{
		cout << "use the stairs";
	}

	return 0;
}