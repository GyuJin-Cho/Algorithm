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

#define MBTI_CNT 16

using namespace std;

int getDist(string a, string b, string c)
{
	int dist = 0;
	for (int i = 0; i < a.size(); i++) 
	{
		dist += (a[i] != b[i]) + (b[i] != c[i]) + (c[i] != a[i]);
	}
	return dist;
}

int solve(int N, vector<string> mbtis)
{
	if (N > MBTI_CNT * 2)
		return 0;

	int answer = 217400000;
	for (int i = 0; i < N; i++) 
	{
		for (int j = i + 1; j < N; j++) 
		{
			for (int k = j + 1; k < N; k++)
			{
				answer = min(answer, getDist(mbtis[i], mbtis[j], mbtis[k]));
			}
		}
	}
	return answer;
}

int main()
{
	int T;
	cin >> T;
	while (T--) 
	{
		int N;
		cin >> N;

		vector<string> mbtis(N);
		for (int i = 0; i < N; i++)
			cin >> mbtis[i];

		cout << solve(N, mbtis)<<'\n';
	}
	return 0;
}