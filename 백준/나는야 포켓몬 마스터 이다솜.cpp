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
	unordered_map<int, string> um1;
	unordered_map<string, int> um2;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		um1[i] = s;
		um2[s] = i;
	}

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (s[0] < 'A')
			cout << um1[stoi(s)] << '\n';
		else
			cout << um2[s] << '\n';
	}

	return 0;
}