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

using namespace std;
vector<int> JumpMap;
bool visit[1001];
struct node
{
	int dist;
	int cnt;
};
void BFS()
{
	queue<node> q;
	q.push({1,0});
	bool check = false;
	visit[1] = true;
	while(!q.empty())
	{
		node n = q.front();
		q.pop();
		if(n.dist==JumpMap.size())
		{
			check = true;
			cout << n.cnt;
		}
		for(int i=0;i<=JumpMap[n.dist-1];i++)
		{
			if (!visit[n.dist + i]&&n.dist+i<=JumpMap.size())
			{
				q.push({ n.dist + i,n.cnt + 1 });
				visit[n.dist + i] = true;
			}
		}
	}
	if (!check)
		cout << -1;
}

int main()
{
	int N;
	cin >> N;
	int JumpCnt;
	while(N--)
	{
		cin >> JumpCnt;
		JumpMap.push_back(JumpCnt);
	}
	BFS();
	return 0;
}