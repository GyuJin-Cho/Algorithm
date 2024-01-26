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
int N, G;

void BFS()
{
	queue<pair<long long, long long>> q;
	q.push({ N,0 });
	while(!q.empty())
	{
		pair<long long, long long> p = q.front();
		q.pop();
		if(p.first>G)
		{
			continue;
		}
		if(p.first==G)
		{
			cout << p.second + 1;
			return;
		}
		string s = to_string(p.first);
		q.push({ p.first * 2,p.second + 1 });
		s += "1";
		q.push({ stoll(s),p.second + 1 });
	}

	cout << -1;
}

int main()
{
	cin >> N >> G;
	BFS();
	return 0;
}