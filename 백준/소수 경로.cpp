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

bool prime[10001];
bool c[10001];

class node
{
public:
	int next;
	int cnt;
	node(int n, int c) : next(n), cnt(c){}
	node() : next(0), cnt(0) {}
	
};

int change(int num, int index, int digit)
{
	if (index == 0 && digit == 0)
		return -1;
	string s = to_string(num);
	s[index] = digit + '0';
	return stoi(s);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=2;i<=10000;i++)
	{
		if(!prime[i])
		{
			for(int j=i*i;j<=10000;j+=i)
			{
				prime[j] = true;
			}
		}
	}

	/*for(int i=0;i<=10000;i++)
	{
		
	}*/
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		memset(c, false, sizeof(c));
		c[n] = true;
		queue<node> q;
		q.push(node(n,0));
		while(!q.empty())
		{
			node now = q.front();
			q.pop();
			if(now.next==m)
			{
				cout << now.cnt<<'\n';
				break;
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<=9;j++)
				{
					int next = change(now.next, i, j);
					if(next!=-1)
					{
						if(!prime[next]&&!c[next])
						{
							q.push(node(next,now.cnt+1));
							c[next] = true;
						}
					}
				}
			}
		}
	}
}