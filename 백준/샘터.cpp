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

int n, k;
int dx[] = { -1,1 };

long long BFS()
{
	queue<int> q;
	unordered_set<int>s;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		q.push(num);
		s.insert(num);
	}

	long long answer = 0;
	long long dis = 1;

	while(!q.empty())
	{
		int size = q.size();
		while(size--)
		{
			int Pos = q.front();
			q.pop();
			for(int i=0;i<2;i++)
			{
				int p = Pos - dx[i];
				if(s.find(p)==s.end())
				{
					k--;
					answer += dis;
					s.insert(p);
					q.push(p);

					if (k == 0)
						return answer;
				}
			}
		}
		dis++;
	}
	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;

	cout << BFS();
	
	return 0;
}