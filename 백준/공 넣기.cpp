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

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> bags(N+1);
	int s, e, n;
	for(int i=0;i<M;i++)
	{
		cin >> s >> e >> n;
		for(int bag=s;bag<=e;bag++)
		{
			bags[bag]=n;
		}
	}
	for (int ball = 1;ball<=N;ball++)
		cout << bags[ball] << ' ';
	return 0;
}