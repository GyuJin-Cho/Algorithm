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
int d[10001];

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
		memset(d, 0, sizeof(d));
		d[n] = 0;
		c[n] = true;
		queue<int> q;
		q.push(n);
		while(!q.empty())
		{
			int now = q.front();
			q.pop();
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<=9;j++)
				{
					int next = change(now, i, j);
					if(next!=-1)
					{
						if(!prime[next]&&!c[next])
						{
							q.push(next);
							d[next] = d[now] + 1;
							c[next] = true;
						}
					}
				}
			}
		}
		cout << d[m]<<'\n';
	}
}