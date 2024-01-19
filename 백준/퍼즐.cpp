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
int arr[3][3];
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int ans = -1;
string s;

void BFS()
{
	set<string> ch;
	queue<pair<string, int>> q;
	q.push({ s,0 });
	ch.insert(s);

	while(!q.empty())
	{
		string now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if(now == "123456780"&&(ans==-1||ans>cnt))
		{
			ans = cnt;
		}

		int zero = now.find('0');
		int y = zero / 3;
		int x = zero % 3;

		for(int i=0;i<4;i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
				continue;
			string ns = now;
			swap(ns[y * 3 + x], ns[ny * 3 + nx]);

			if(ch.find(ns)==ch.end())
			{
				ch.insert(ns);
				q.push({ ns,cnt + 1 });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<3;i++)
	{
		for (int j = 0; j < 3; j++)
		{
			char c;
			cin >> c;
			s += c;
		}
	}
	BFS();
	cout << ans;
	return 0;
}