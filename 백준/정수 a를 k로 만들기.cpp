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

void BFS(int n,int k)
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));
	vector<bool> ch(k + 1);
	while(!q.empty())
	{
		int N, cnt;
		tie(N, cnt) = q.front();
		q.pop();
		if(N==k)
		{
			cout << cnt;
			return;
		}
		if(N+1<k+1&&!ch[N+1])
		{
			q.push(make_pair(N + 1, cnt + 1));
			ch[N + 1] = true;
		}
		if(N*2<k+1&&!ch[N*2])
		{
			q.push(make_pair(N * 2, cnt + 1));
			ch[N * 2] = true;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	BFS(n,k);

	return 0;
}