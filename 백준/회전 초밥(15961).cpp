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
int N, D, K, C, arr[3000001];
int s, cnt, answer;
unordered_map<int, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < K - 1; i++)
		m[arr[i]]++;

	int e = K - 1;
	for(int i=0;i<N;i++)
	{
		int del = arr[s];
		int cur = arr[e % N];
		m[cur]++;
		int num = m.size();
		if (m.find(C) == m.end())
			answer = max(answer, num + 1);
		else
			answer = max(answer, num);
		m[del]--;
		if (m[del] == 0)
			m.erase(m.find(del));
		s++;
		e++;
	}
	cout << answer;

	return 0;
}