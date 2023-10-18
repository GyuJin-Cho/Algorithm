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
int const MAX = 100001;
int n, k;
bool visit[MAX];

class node
{
public:
	int pos;
	int cnt;
	node(int p, int c) : pos(p), cnt(c){}
	node() : pos(0),cnt(0){}
};


void BFS()
{
	queue<node> q;
	q.push(node(n,0));
	while(!q.empty())
	{
		node N = q.front();
		q.pop();

		if(N.pos==k)
		{
			cout << N.cnt;
			return;
		}

		for(int i=0;i<3;i++)
		{
			int nx;
			if(i==0)
			{
				nx = N.pos * 2;
			}
			else if(i==1)
			{
				nx = N.pos + 1;
			}
			else
			{
				nx = N.pos - 1;
			}
			if(nx<MAX&&nx>-1)
			{
				if(!visit[nx])
				{
					q.push(node(nx, N.cnt + 1));
					visit[nx] = true;
				}
			}
		}
	}
}

int main()
{
	
	cin >> n >> k;
	BFS();

	return 0;
}