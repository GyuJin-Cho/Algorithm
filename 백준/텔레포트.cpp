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
int N, T, M;
int Map[1001][1001];
vector<tuple<int, int, int>>v;
vector<pair<int, int>> cmd;
int Dist(int x, int y, int xx, int yy)
{
	return (abs(x - xx) + abs(y - yy));
}

void Floyd()
{
	for(int i=0;i<N;i++)
	{
		int x, y, s;
		tie(x, y, s) = v[i];
		for(int j=0;j<N;j++)
		{
			if(i==j)
				continue;
			int Distance;
			int xx, yy, ss;
			tie(xx, yy, ss) = v[j];

			Distance = Dist(x, y, xx, yy);
			if(s==1&&ss==1)
			{
				if (Distance > T)
					Distance = T;
			}
			Map[i][j] = Distance;
		}
	}
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(i==j)
					continue;
				if (Map[i][j] > Map[i][k] + Map[k][j])
					Map[i][j] = Map[i][k] + Map[k][j];
			}
		}
	}
	for(int i=0;i<M;i++)
	{
		int pos = cmd[i].first;
		int pos2 = cmd[i].second;

		cout << Map[pos][pos2]<<'\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> T;
	for(int i=0;i<N;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back(make_tuple(b, c, a));
	}
	cin >> M;
	for(int i=0;i<M;i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		cmd.push_back(make_pair(a, b));
	}
	Floyd();
	return 0;
}