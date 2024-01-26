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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	unordered_set<string> s;
	string input;
	for(int i=0;i<N;i++)
	{
		cin >> input;
		s.insert(input);
	}
	int ans = 0;
	for(int i=0;i<M;i++)
	{
		cin >> input;
		if (s.find(input) != s.end())
			ans++;
	}
	cout << ans;
	return 0;
}